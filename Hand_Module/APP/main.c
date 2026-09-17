/*
 * main.c
 * Author : Eltawel
 */ 

#include "main.h"

#define HAND_SPEED_BASE				70
#define HAND_SPEED_BENT				100
#define HAND_LOOP_DELAY_MS			100

static u8 MPU_u8DirectionToCommand(u8 copy_u8Dir)
{
	switch(copy_u8Dir)
	{
		case MPU_Y_DIR_FORWARD:	return 'F';
		case MPU_Y_DIR_BACKWARD:	return 'B';
		case MPU_Y_DIR_RIGHT:		return 'R';
		case MPU_Y_DIR_LEFT:		return 'L';
		case MPU_Y_DIR_BASE:
		default:					return 'S';
	}
}

static void LCD_voidPrintDirection(u8 copy_u8Dir)
{
	switch(copy_u8Dir)
	{
		case MPU_Y_DIR_BACKWARD:	LCD_voidSendString((u8*)"Back    "); break;
		case MPU_Y_DIR_BASE:		LCD_voidSendString((u8*)"Stop    "); break;
		case MPU_Y_DIR_RIGHT:		LCD_voidSendString((u8*)"Right   "); break;
		case MPU_Y_DIR_LEFT:		LCD_voidSendString((u8*)"Left    "); break;
		case MPU_Y_DIR_FORWARD:	LCD_voidSendString((u8*)"Forward "); break;
		default:					LCD_voidSendString((u8*)"?       "); break;
	}
}


int main(void)
{

	TIM0_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	UART_voidInit();

	LCD_voidGotoXY(0, 0);
	LCD_voidSendString((u8*)"Starting MPU...");

	TWI_voidMasterInit();
	MPU_voidInit();

	LCD_voidClear();

	u8 Loc_u8FlexState = 0;
	u8 Loc_u8YDirection = 0;
	u8 Loc_u8Command = 0;
	u8 Loc_u8Speed = 0;
	
    while (1) 
    {
		 Loc_u8YDirection = MPU_u8GetYDirection();
		Loc_u8FlexState  = FLEX_u16GetFingerState(FLEX_FIRST_FINGER);

		Loc_u8Command = MPU_u8DirectionToCommand(Loc_u8YDirection);
		Loc_u8Speed   = (Loc_u8FlexState == FLEX_STATE_BENT) ? HAND_SPEED_BENT : HAND_SPEED_BASE;

		/* Hand at rest (Base -> Stop) always sends speed 0, regardless
		 * of the flex sensor, so the car doesn't creep at 70% while "stopped" */
		if(Loc_u8Command == 'S')
		{
			Loc_u8Speed = 0;
		}

		/* Protocol: exactly 2 bytes per update - [command][speed] */
		UART_voidSendData(Loc_u8Command);
		UART_voidSendData(Loc_u8Speed);

		/* Line 1: current direction */
		LCD_voidGotoXY(0, 0);
		LCD_voidSendString((u8*)"Dir: ");
		LCD_voidPrintDirection(Loc_u8YDirection);

		/* Line 2: current speed */
		LCD_voidGotoXY(0, 1);
		LCD_voidSendString((u8*)"Speed: ");
		LCD_voidSendNum(Loc_u8Speed);
		LCD_voidSendString((u8*)"   ");

		TIM0_voidDelayMs(HAND_LOOP_DELAY_MS);
    }
}
