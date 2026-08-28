/*
 * ADC_prog.c
 *
 * Created: 8/10/2026 6:32:51 AM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_CFG.h"
#include "ADC_interface.h"
#include "ADC_REG.h"

void ADC_voidInit(void)
{
	/* 1- Select Reference Voltage  */
		SET_BIT(ADMUX_REG, REFS0_BIT);
		CLEAR_BIT(ADMUX_REG, REFS1_BIT);
		
	/* 2- Select Right Adjustment */
		SET_BIT(ADMUX_REG, ADLAR_BIT);
		
	/* 3- Select Prescaler */
		ADCSRA_REG &= 0xF8;
		ADCSRA_REG |= ADC_CLK_128;
		
	/* 4- ADC Enable */
		SET_BIT(ADCSRA_REG, ADEN_BIT);
}

u8 ADC_u8ReadInputChannel(u8 copy_u8channel)
{
	/* 1- Select Channel */
		ADMUX_REG &= 0xE0;
		ADMUX_REG |= copy_u8channel;
	/* 3- Start Conversion */
		SET_BIT(ADCSRA_REG, ADSC_BIT);
		while(GET_BIT(ADCSRA_REG, ADIF_BIT) == 0);
	/* Return Data */
		return ADCH_REG;
}