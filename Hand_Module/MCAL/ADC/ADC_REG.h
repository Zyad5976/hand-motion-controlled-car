/*
 * ADC_REG.h
 *
 * Created: 8/10/2026 6:32:04 AM
 *  Author: Eltawel
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

/************************************************************************/
/*                               Registers                              */
/************************************************************************/

#define ADMUX_REG					*((volatile u8 *)0x27)
#define ADCSRA_REG					*((volatile u8 *)0x26)
#define ADCH_REG					*((volatile u8 *)0x25)
#define ADCL_REG					*((volatile u8 *)0x24)


/************************************************************************/
/*                              Register Bits                           */
/************************************************************************/

/* ADMUX_REG Bits */
#define REFS1_BIT				7	/* Reference Selection Bits */
#define REFS0_BIT				6	/* Reference Selection Bits */
#define ADLAR_BIT				5	/* ADC Left Adjust Result */
#define MUX4_BIT				4	/* Analog Channel and Gain Selection Bits */
#define MUX3_BIT				3	/* Analog Channel and Gain Selection Bits */
#define MUX2_BIT				2	/* Analog Channel and Gain Selection Bits */
#define MUX1_BIT				1	/* Analog Channel and Gain Selection Bits */
#define MUX0_BIT				0	/* Analog Channel and Gain Selection Bits */


/* ADCSRA_REG Bits */
#define ADEN_BIT				7	/* ADC Enable */
#define ADSC_BIT				6	/* ADC Start Conversion */
#define ADATE_BIT				5	/* ADC Auto Trigger Enable */
#define ADIF_BIT				4	/* ADC Interrupt Flag */
#define ADIE_BIT				3	/* ADC Interrupt Enable */
#define ADPS2_BIT				2	/* ADC Prescaler Select Bits */
#define ADPS1_BIT				1	/* ADC Prescaler Select Bits */
#define ADPS0_BIT				0	/* ADC Prescaler Select Bits */

#endif /* ADC_REG_H_ */