/*
 * TIM0_interface.h
 *
 * Created: 8/8/2026 3:17:17 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

/**
 * @brief Initializes Timer0 in CTC (Clear Timer on Compare) mode.
 *        Configures the prescaler (as defined in TIM0_CFG.h) and loads
 *        OCR0 with the value corresponding to a 1ms tick @ F_CPU.
 *        Does not enable any interrupts; this driver operates via polling.
 * @param None
 * @return None
 */
void TIM0_voidInit(void);

/**
 * @brief Generates a blocking (busy-wait) delay in milliseconds.
 *        Internally polls the OCF0 flag once per 1ms tick and repeats
 *        for the requested number of milliseconds.
 * @param copy_u16tim Number of milliseconds to delay.
 *                     Valid range: 0 to 65535 ms.
 * @return None
 * @note This function blocks CPU execution for the entire duration;
 *       it does not yield control back until the delay completes.
 */
void TIM0_voidDelayMs(u16 copy_u16tim);

#endif /* TIM0_INTERFACE_H_ */