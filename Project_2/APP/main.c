/*
 * Project_2.c
 *
 * Created: 8/7/2026 6:40:03 PM
 * Author : Eltawel
 */ 

#include "main.h"


int main(void)
{
	
	TIM0_voidInit();
	TIM2_voidInit();
	UART_voidInit();
	DCMOTOR_voidInit();
	LCD_voidInit();
	
    while (1) 
    {
		u8 Loc_UART_ReceivedCommand = UART_u8ReceiveData();
		
		switch(Loc_UART_ReceivedCommand)
		{
			case 'F':
				LED_voidOFF(DIO_PORTA, DIO_PIN0);
				LED_voidOFF(DIO_PORTA, DIO_PIN1);
				DCMOTOR_voidForward(70);
				LCD_voidClear();
				LCD_voidSendString((u8*)"Forward");
				break;
				
			case 'B':
				DCMOTOR_voidReverse(50);
				LED_voidON(DIO_PORTA, DIO_PIN0);
				LED_voidON(DIO_PORTA, DIO_PIN1);
				LCD_voidClear();
				LCD_voidSendString((u8*)"Backward");
				break;
			
			case 'L':
				LED_voidOFF(DIO_PORTA, DIO_PIN0);
				LED_voidOFF(DIO_PORTA, DIO_PIN1);
				DCMOTOR_voidLeft(70);
				LCD_voidClear();
				LCD_voidSendString((u8*)"Left");
				break;
				
			case 'R':
				LED_voidOFF(DIO_PORTA, DIO_PIN0);
				LED_voidOFF(DIO_PORTA, DIO_PIN1);
				DCMOTOR_voidRight(70);
				LCD_voidClear();
				LCD_voidSendString((u8*)"Right");
				break;
				
			case 'S':
				LED_voidOFF(DIO_PORTA, DIO_PIN0);
				LED_voidOFF(DIO_PORTA, DIO_PIN1);
				DCMOTOR_voidStop(0);
				LCD_voidClear();
				LCD_voidSendString((u8*)"Stop");
				break;
			
			default:
			
			break;
		}
    }
}

