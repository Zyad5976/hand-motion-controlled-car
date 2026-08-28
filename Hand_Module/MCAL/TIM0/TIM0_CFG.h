/*
 * TIM0_CFG.h
 *
 * Created: 8/8/2026 3:16:47 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_CFG_H_
#define TIM0_CFG_H_

/* TIM0 Modes */
#define TIM0_NORMAL					0
#define TIM0_PWM_PHASECORRECT		1
#define TIM0_CTC					2
#define TIM0_FASTPWM				3

/* Macros */
#define TIM0_NO_CLK_SOURCE			0
#define TIM0_CLK_NO_PRESCALING		1
#define TIM0_8_CLK					2
#define TIM0_64_CLK					3
#define TIM0_256_CLK				4
#define TIM0_1024_CLK				5

/* Select Prescaler */
#define TIM0_PRESCALER				TIM0_64_CLK

/* OCR0 Val */
#define TIM0_OCR0_VALUE				249

#endif /* TIM0_CFG_H_ */