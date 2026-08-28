/*
 * FLEX_interface.h
 *
 * Created: 8/11/2026 7:06:46 AM
 *  Author: Eltawel
 */ 


#ifndef FLEX_INTERFACE_H_
#define FLEX_INTERFACE_H_

/**
 * @brief Reads a specific finger's flex sensor and returns whether
 *        it is currently flat or bent, based on FLEX_THRESHOLD.
 * @param copy_u8channel ADC channel connected to the finger's sensor
 *                        (use FLEX_xxx_CHANNEL macros from FLEX_CFG.h).
 * @return u8 FLEX_STATE_FLAT or FLEX_STATE_BENT
 */
u8 FLEX_u8GetFingerState(u8 copy_u8channel);

#endif /* FLEX_INTERFACE_H_ */