/*
 * TIM2_CFG.h
 *
 * Created: 8/8/2026 1:02:16 PM
 *  Author: Eltawel
 */ 


#ifndef TIM2_CFG_H_
#define TIM2_CFG_H_

/* TIM0 Modes */
#define TIM2_NORMAL					0
#define TIM2_PWM_PHASECORRECT		1
#define TIM2_CTC					2
#define TIM2_FASTPWM				3

/* Select PWM Mode  */
#define TIM2_OC2_DISCONECTED		0
#define TIM2_REVERSED				1
#define TIM2_NON_INVERTING_PWM		2
#define	TIM2_INVERTING_PWM			3

/* Select MODE */
#define TIM2_PWM_MODE				TIM2_NON_INVERTING_PWM

/* TIM2 Prescalling */
#define TIM2_NO_CLK_SOURCE			0
#define TIM2_CLK_NO_PRESCALING		1
#define TIM2_8_CLK					2
#define TIM2_32_CLK					3
#define TIM2_64_CLK					4
#define TIM2_128_CLK				5
#define TIM2_256_CLK				6
#define TIM2_1024_CLK				7

/* Select Prescaler */
#define TIM2_PRESCALER				TIM2_64_CLK

#endif /* TIM2_CFG_H_ */