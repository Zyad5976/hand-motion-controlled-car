/*
 * ADC_interface.h
 *
 * Created: 8/10/2026 6:32:18 AM
 *  Author: Eltawel
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/**
 * @brief Initializes the ADC peripheral: enables it, sets the voltage
 *        reference and prescaler as configured in ADC_CFG.h.
 *        Must be called once before using ADC_u8ReadInputChannel().
 * @param None
 * @return None
 */
void ADC_voidInit(void);

/**
 * @brief Reads a single analog value from the specified ADC channel
 *        and returns the result as an 8-bit value (upper 8 bits of
 *        the 10-bit conversion, i.e. ADCH only — see note).
 *        This function is blocking: it polls the ADIF flag until the
 *        conversion completes.
 * @param copy_u8channel ADC channel to read from.
 *                        Valid range: 0 to 7 (e.g. use ADC_CHANNEL_0
 *                        through ADC_CHANNEL_7 from ADC_CFG.h).
 * @return u8 Converted analog value, ranging from 0 to 255.
 * @note This assumes ADLAR is set to left-adjust the result, so that
 *       reading ADCH alone gives an 8-bit approximation of the full
 *       10-bit conversion.
 */
u8 ADC_u8ReadInputChannel(u8 copy_u8channel);

#endif /* ADC_INTERFACE_H_ */