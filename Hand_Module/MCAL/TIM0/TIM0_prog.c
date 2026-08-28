/*
 * TIM0_prog.c
 *
 * Created: 8/8/2026 3:17:30 AM
 *  Author: Eltawel
 */ 
#include "../../LIB/Platform_CFG.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIM0_CFG.h"
#include "TIM0_interface.h"
#include "TIM0_REG.h"

void TIM0_voidInit(void)
{
	/* 1- Select Mode --> CTC Mode / 2- Select Prescaler --> 64 */
		TCCR0_REG = 0x0B;
		
	/* 3- Load OCR0 Val */
		OCR0_REG = TIM0_OCR0_VALUE;
		
}

void TIM0_voidDelayMs(u16 copy_u16tim)
{
	u16 Loc_Counter = 0;
	
	for(Loc_Counter = 0; Loc_Counter < copy_u16tim; Loc_Counter++)
	{
		while(GET_BIT(TIFR_REG, OCF0_BIT) == 0);
		
		SET_BIT(TIFR_REG, OCF0_BIT);
	}
}