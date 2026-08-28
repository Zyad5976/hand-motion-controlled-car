/*
 * LED_interface.h
 *
 * Created: 8/8/2026 5:04:57 PM
 *  Author: Eltawel
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/**
 * @brief Turns ON a specific LED connected to the given port and pin.
 * @param copy_u8port Port ID the LED is connected to (e.g. PORTA, PORTB...).
 * @param copy_u8pin  Pin number within the port (0-7).
 * @return None
 * @note Assumes the LED is active-HIGH (logic 1 = ON). The pin must be
 *       configured as OUTPUT beforehand (via the DIO driver) for this
 *       function to have any effect.
 */
void LED_voidON(u8 copy_u8port, u8 copy_u8pin);

/**
 * @brief Turns OFF a specific LED connected to the given port and pin.
 * @param copy_u8port Port ID the LED is connected to.
 * @param copy_u8pin  Pin number within the port (0-7).
 * @return None
 * @note Assumes the LED is active-HIGH (logic 1 = ON, logic 0 = OFF).
 */
void LED_voidOFF(u8 copy_u8port, u8 copy_u8pin);

/**
 * @brief Toggles the current state of a specific LED (ON becomes OFF
 *        and vice versa).
 * @param copy_u8port Port ID the LED is connected to.
 * @param copy_u8pin  Pin number within the port (0-7).
 * @return None
 */
void LED_voidToggle(u8 copy_u8port, u8 copy_u8pin);

#endif /* LED_INTERFACE_H_ */