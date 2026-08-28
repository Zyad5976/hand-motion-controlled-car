/*
 * TIM2_interface.h
 *
 * Created: 8/8/2026 1:02:30 PM
 *  Author: Eltawel
 */ 


#ifndef TIM2_INTERFACE_H_
#define TIM2_INTERFACE_H_

/**
 * @brief Initializes Timer2 in Fast PWM mode with Non-Inverting output
 *        on OC2 pin, using the prescaler defined in TIM2_CFG.h.
 *        The PWM signal starts immediately at 0% duty cycle (motor stopped).
 * @param None
 * @return None
 */
void TIM2_voidInit(void);

/**
 * @brief Sets the PWM duty cycle, which directly controls motor speed.
 *        Internally converts the percentage to the corresponding OCR2 value.
 * @param copy_u8duty Duty cycle percentage.
 *                     Valid range: 0 (motor stopped) to 100 (max speed).
 * @return None
 * @note Values above 100 will be clipped/undefined behavior; caller must
 *       ensure the input is within range.
 */
void TIM2_voidFastPWM(u8 copy_u8duty);

#endif /* TIM2_INTERFACE_H_ */