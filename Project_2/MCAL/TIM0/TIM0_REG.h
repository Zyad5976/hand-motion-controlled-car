/*
 * TIM0_REG.h
 *
 * Created: 8/8/2026 3:16:58 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_REG_H_
#define TIM0_REG_H_

/* TIM0 Registers */
#define TCCR0_REG				*((volatile u8*)0x53)
#define TCNT0_REG				*((volatile u8*)0x52)
#define OCR0_REG				*((volatile u8*)0x5C)
#define TIMSK_REG				*((volatile u8*)0x59)
#define TIFR_REG				*((volatile u8*)0x58)

/* TCCR0_REG bits */
#define FOC0_BIT				7	/* FORCE UOUTPU COMPARE */
#define WGM00_BIT				6	/* WAVEFORM GENERATION MODE */
#define COM01_BIT				5	/* COMPARE MATCH OUPTUT MODE */
#define COM00_BIT				4	/* COMPARE MATCH OUPTUT MODE */
#define WGM01_BIT				3	/* WAVEFORM GENERATION MODE */
#define CS02_BIT				2	/* CLOCK SELECT */
#define CS01_BIT				1	/* CLOCK SELECT */
#define CS00_BIT				0	/* CLOCK SELECT */

/* TIMSK_REG Bits */
#define OCIE0_BIT				1	/* T/C 0 OUTPUT COMPARE MATCH INTERRUPT ENABLE */
#define TOIE0_BIT				0	/* T/C 0 OUTPUT OVERFLOW INTERRUPT ENABLE */

/* TIFR_REG Bits */
#define OCF0_BIT				1	/* Output Compare Flag 0 */
#define TOV0_BIT				0	/* T/C 0 Overflow Flag */

#endif /* TIM0_REG_H_ */