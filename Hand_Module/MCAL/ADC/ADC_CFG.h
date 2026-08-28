/*
 * ADC_CFG.h
 *
 * Created: 8/10/2026 6:33:18 AM
 *  Author: Eltawel
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/* Voltage Refrence Selection */
#define ADC_INTERNAL_VREF_TURNOFF										0
#define ADC_AVCC_WITH_EXTERNAL_CAPACITOR_AREF_PIN						1
#define ADC_RESERVED													2
#define ADC_INTERNAL_REFERENCE_WITH_EXTERNAL_CAPACITOR_AREF_PIN			3

/* Select Voltage Reference */
#define ADC_VREF_SELECTED    ADC_AVCC_WITH_EXTERNAL_CAPACITOR_AREF_PIN

/* ADC Single Input Ended Channels */
#define ADC0						0
#define ADC1						1
#define ADC2						2
#define ADC3						3
#define ADC4						4
#define ADC5						5
#define ADC6						6
#define ADC7						7

/* ADC Prescaler */
#define ADC_CLK_2					1
#define ADC_CLK_4					2
#define ADC_CLK_8					3
#define ADC_CLK_16					4
#define ADC_CLK_32					5
#define ADC_CLK_64					6
#define ADC_CLK_128					7

/*  Select Prescaler */
#define ADC_PRESCALER				ADC_CLK_128

#endif /* ADC_CFG_H_ */