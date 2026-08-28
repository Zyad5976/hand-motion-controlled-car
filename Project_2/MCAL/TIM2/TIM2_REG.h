/*
 * TIM2_REG.h
 *
 * Created: 8/8/2026 1:02:43 PM
 *  Author: Eltawel
 */ 


#ifndef TIM2_REG_H_
#define TIM2_REG_H_

/************************************************************************/
/*                               Registers                              */
/************************************************************************/

#define TCCR2_REG				*((volatile u8*)0x45)
#define TCNT2_REG				*((volatile u8*)0x44)
#define OCR2_REG				*((volatile u8*)0x43)
#define TIMSK_REG				*((volatile u8*)0x59)
#define TIFR_REG				*((volatile u8*)0x58)

/************************************************************************/
/*                              Registers Bits                          */
/************************************************************************/

/* TCCR2_REG Bits */
#define FOC2_BIT				7	/* Force Output Compare */
#define WGM20_BIT				6	/* Waveform Generation Mode */
#define COM21_BIT				5	/* Compare Match Output Mode */
#define COM20_BIT				4	/* Compare Match Output Mode */
#define WGM21_BIT				3	/* Waveform Generation Mode */
#define CS22_BIT				2	/* Clock Select */
#define CS21_BIT				1	/* Clock Select */
#define CS20_BIT				0	/* Clock Select */


/* TIMSK_REG Bits */
#define OCIE2_BIT				7	/* T/C 2 Output Compare Match Interrupt Enable */
#define TOIE2_BIT				6	/* T/C 2 Overflow Interrupt Enable */

/* TIFR_REG Bits */
#define OCF2_BIT				7	/* Output Compare Flag 2 */
#define TOV2_BIT				6	/* T/C 2 Overflow Flag */


#endif /* TIM2_REG_H_ */