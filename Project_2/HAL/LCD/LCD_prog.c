/*
 * LCD_prog.c
 *
 * Created: 8/8/2026 5:35:16 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TIM0/TIM0_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_CFG.h"

/**
 * @brief Sends the upper nibble (4 bits) of a byte to the LCD data pins
 *        (D4-D7), then triggers an Enable pulse to latch it.
 *        Used internally to implement 4-bit mode communication, where
 *        every full byte (command or data) is split into two nibbles.
 * @param copy_u8data The nibble to send, expected in the upper 4 bits
 *                     of the byte (lower 4 bits are ignored/masked).
 * @return None
 */
static void LCD_voidSendHalfData(u8 copy_u8data)
{
	static const u8 Loc_LCD_Bits[LCD_4_BIT] = {LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN};
		
	u8 Loc_LCD_Counter = 0;
		
	for(Loc_LCD_Counter = 0; Loc_LCD_Counter < LCD_4_BIT; Loc_LCD_Counter++)
	{
		DIO_voidSetPinVal(LCD_DPORT, Loc_LCD_Bits[Loc_LCD_Counter], GET_BIT(copy_u8data, Loc_LCD_Counter));
	}	
}

/**
 * @brief Generates the Enable (E) pulse required by the HD44780
 *        controller to latch data/command bits that are currently
 *        set on the data pins. Sequence: E=1, short delay, E=0.
 * @param None
 * @return None
 */
static void LCD_voidSendEnablePulse()
{
	DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, HIGH);
	TIM0_voidDelayMs(1);
	DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, LOW);
}

void LCD_voidInit(void)
{
	/* 1- Set Ports(CPORT , DPORT) Directions */
		DIO_voidSetPortDir(LCD_CPORT, LCD_CPORT_DIR);
		DIO_voidSetPortDir(LCD_DPORT, LCD_DPORT_DIR);
	
	/* 2- Delay (40ms) */
		TIM0_voidDelayMs(40);
	
	/* 3- Send Half Data */
		LCD_voidSendHalfData(0x02);
		LCD_voidSendEnablePulse();
		LCD_voidSendHalfData(0x02);
		LCD_voidSendEnablePulse();
		LCD_voidSendHalfData(0x08);
		LCD_voidSendEnablePulse();
		
	/* 4- Send Command */
		LCD_voidSendCommand(0x0C);
		
	/* 5- Clear LCD */
		LCD_voidClear();	
}

void LCD_voidSendCommand(u8 copy_u8command)
{
	/* 1- Set RS --> 0 */
		DIO_voidSetPinVal(LCD_CPORT, LCD_RS_PIN, LOW);
		
	/* 2- Set RW --> GND */
	
	/* 3- Send Half Data */
		LCD_voidSendHalfData(copy_u8command >> 4);
		LCD_voidSendEnablePulse();
		LCD_voidSendHalfData(copy_u8command);
		LCD_voidSendEnablePulse();
}

void LCD_voidSendData(u8 copy_u8data)
{
	/* 1- Set RS --> 1 */
	DIO_voidSetPinVal(LCD_CPORT, LCD_RS_PIN, HIGH);
	
	/* 2- Set RW --> GND */
	
	/* 3- Send Half Data */
	LCD_voidSendHalfData(copy_u8data >> 4);
	LCD_voidSendEnablePulse();
	LCD_voidSendHalfData(copy_u8data);
	LCD_voidSendEnablePulse();
}

void LCD_voidClear()
{
	LCD_voidSendCommand(0x01);
}

void LCD_voidSendString(u8 *copy_pu8string)
{
	u8 Loc_LCD_Counter = 0;
	
	while(copy_pu8string[Loc_LCD_Counter] != nul)
	{
		LCD_voidSendData(copy_pu8string[Loc_LCD_Counter]);
		Loc_LCD_Counter++;
	}
}

void LCD_voidSendNum(u32 copy_u32num)
{
	s8 Loc_LCD_Counter = 0;
	u8 Loc_LCD_Arr[10];
	
	if(copy_u32num == 0)
	{
		LCD_voidSendData('0');
		return;
	}
	
	for(Loc_LCD_Counter = 0; copy_u32num != 0; Loc_LCD_Counter++)
	{
		Loc_LCD_Arr[Loc_LCD_Counter] = copy_u32num % 10 + 48;
		copy_u32num /= 10;
	}
	Loc_LCD_Counter--;
	
	while(Loc_LCD_Counter >= 0)
	{
		LCD_voidSendData(Loc_LCD_Arr[Loc_LCD_Counter]);
		Loc_LCD_Counter--;
	}
}

void LCD_voidGotoXY(u8 copy_u8x, u8 copy_u8y)
{
	u8 Loc_LCD_DDRAM_Address = (copy_u8x + (copy_u8y * 0x40));
	
	SET_BIT(Loc_LCD_DDRAM_Address, 7);
	
	LCD_voidSendCommand(Loc_LCD_DDRAM_Address);
}

void LCD_voidDisplayGraphicalData(u8 *copy_parr, u8 copy_u8pattern, u8 copy_u8x, u8 copy_u8y)
{
	u8 Loc_LCD_CGRAM_Adress = copy_u8pattern * 8;
	u8 Loc_LCD_Counter = 0;
	
	CLEAR_BIT(Loc_LCD_CGRAM_Adress, 7);
	SET_BIT(Loc_LCD_CGRAM_Adress, 6);
	
	LCD_voidSendCommand(Loc_LCD_CGRAM_Adress);
	
	for(Loc_LCD_Counter = 0; Loc_LCD_Counter < 8; Loc_LCD_Counter++)
	{
		LCD_voidSendData(copy_parr[Loc_LCD_Counter]);
	}
	
	LCD_voidGotoXY(copy_u8x, copy_u8y);
	LCD_voidSendData(copy_u8pattern);
}