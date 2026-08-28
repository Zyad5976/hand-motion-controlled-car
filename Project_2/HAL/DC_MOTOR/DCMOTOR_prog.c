/*
 * DCMOTOR_prog.c
 *
 * Created: 8/8/2026 8:11:40 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TIM2/TIM2_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "DCMOTOR_CFG.h"
#include "DCMOTOR_interface.h"

void DCMOTOR_voidInit()
{
	/* Set Motor Pins */
	DIO_voidSetPinDir(DCMOTOR_EN1_PORT, DCMOTOR_EN1_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_EN2_PORT, DCMOTOR_EN2_PIN, OUTPUT);
	
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A1_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A2_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A3_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A4_PIN, OUTPUT);
}

void DCMOTOR_voidForward(u8 copy_u8speed)
{
	TIM2_voidFastPWM(copy_u8speed);
	
	/* motor 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	
	/* motor 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
}

void DCMOTOR_voidReverse(u8 copy_u8speed)
{
	TIM2_voidFastPWM(copy_u8speed);
	
	/* motor 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, HIGH);
	
	/* motor 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, HIGH);
}

void DCMOTOR_voidLeft(u8 copy_u8speed)
{
	TIM2_voidFastPWM(copy_u8speed);
	
	/* motor 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	
	/* motor 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
}

void DCMOTOR_voidRight(u8 copy_u8speed)
{
	TIM2_voidFastPWM(copy_u8speed);
	
	/* motor 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	
	/* motor 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
}

void DCMOTOR_voidStop(u8 copy_u8speed)
{
	TIM2_voidFastPWM(copy_u8speed);
	
	/* motor 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	
	/* motor 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
}