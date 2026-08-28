/*
 * BUZZER_prog.c
 *
 * Created: 8/8/2026 5:30:44 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "BUZZER_interface.h"

void BUZZER_voidON(u8 copy_u8port, u8 copy_u8pin)
{
	DIO_voidSetPinDir(copy_u8port, copy_u8pin, OUTPUT);
	DIO_voidSetPinVal(copy_u8port, copy_u8pin, HIGH);
}

void BUZZER_voidOFF(u8 copy_u8port, u8 copy_u8pin)
{
	DIO_voidSetPinDir(copy_u8port, copy_u8pin, OUTPUT);
	DIO_voidSetPinVal(copy_u8port, copy_u8pin, LOW);
}

void BUZZER_voidToggle(u8 copy_u8port, u8 copy_u8pin)
{
	DIO_voidSetPinDir(copy_u8port, copy_u8pin, OUTPUT);
	DIO_voidTogglePinVal(copy_u8port, copy_u8pin);
}