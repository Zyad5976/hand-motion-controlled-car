/*
 * BUZZER_interface.h
 *
 * Created: 8/8/2026 5:30:33 PM
 *  Author: Eltawel
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

/**
 * @brief Turns ON the buzzer connected to the given port and pin.
 * @param copy_u8port Port ID the buzzer (driving transistor's base) is connected to.
 * @param copy_u8pin  Pin number within the port (0-7).
 * @return None
 * @note The buzzer is driven indirectly through an NPN transistor switch
 *       (base connected via a current-limiting resistor to this pin).
 *       The pin must be configured as OUTPUT beforehand (via the DIO driver).
 */
void BUZZER_voidON(u8 copy_u8port, u8 copy_u8pin);

/**
 * @brief Turns OFF the buzzer connected to the given port and pin.
 * @param copy_u8port Port ID the buzzer driving pin is connected to.
 * @param copy_u8pin  Pin number within the port (0-7).
 * @return None
 */
void BUZZER_voidOFF(u8 copy_u8port, u8 copy_u8pin);

/**
 * @brief Toggles the current state of the buzzer (ON becomes OFF and
 *        vice versa).
 * @param copy_u8port Port ID the buzzer driving pin is connected to.
 * @param copy_u8pin  Pin number within the port (0-7).
 * @return None
 */
void BUZZER_voidToggle(u8 copy_u8port, u8 copy_u8pin);

#endif /* BUZZER_INTERFACE_H_ */