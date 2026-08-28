/*
 * FLEX_prog.c
 *
 * Created: 8/11/2026 7:07:00 AM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "FLEX_CFG.h"
#include "FLEX_interface.h"

u8 FLEX_u8GetFingerState(u8 copy_u8channel)
{
	u8 Loc_FLEX_VAL = ADC_u8ReadInputChannel(copy_u8channel);
	
	if (Loc_FLEX_VAL >= FLEX_THRESHOLD)
	{
		return FLEX_STATE_BENT;
	}
	else
	{
		return FLEX_STATE_FLAT;
	}
}