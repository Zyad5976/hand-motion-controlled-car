/*
 * TIM2_prog.c
 *
 * Created: 8/8/2026 1:02:57 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/Platform_CFG.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIM2_CFG.h"
#include "TIM2_interface.h"
#include "TIM2_REG.h"

void TIM2_voidInit(void)
{
	/* 1- Select Mode --> Fast PWM */
		SET_BIT(TCCR2_REG, WGM21_BIT);
		SET_BIT(TCCR2_REG, WGM20_BIT);
		
	/* 2- non inverting mode */
		SET_BIT(TCCR2_REG, COM21_BIT);
		CLEAR_BIT(TCCR2_REG, COM20_BIT);
		
	/* 3- Prescaler */
		SET_BIT(TCCR2_REG, CS22_BIT);
		CLEAR_BIT(TCCR2_REG, CS21_BIT);
		CLEAR_BIT(TCCR2_REG, CS20_BIT);
		
	/* Init Motor Speed --> 0 */
		OCR2_REG = 0;
}

void TIM2_voidFastPWM(u8 copy_u8duty)
{
	if(copy_u8duty > 100)
	{
		copy_u8duty = 100;
	}
	OCR2_REG = (copy_u8duty * 255) / 100;
}