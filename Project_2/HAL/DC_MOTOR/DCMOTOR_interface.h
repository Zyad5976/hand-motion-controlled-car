/*
 * DCMOTOR_interface.h
 *
 * Created: 8/8/2026 8:11:25 PM
 *  Author: Eltawel
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

/**
 * @brief Initializes the direction control pins for both motors as
 *        OUTPUT, and ensures both motors start in the STOP state.
 *        Does NOT initialize Timer2/PWM; TIM2_voidInit() must be
 *        called separately (e.g. in main, before this function).
 * @param None
 * @return None
 */
void DCMOTOR_voidInit(void);

/**
 * @brief Drives both motors forward (same direction), causing the
 *        car to move straight ahead.
 * @param copy_u8speed Speed percentage. Valid range: 0 (stopped) to 100 (max speed).
 * @return None
 */
void DCMOTOR_voidForward(u8 copy_u8speed);

/**
 * @brief Drives both motors in reverse (same direction), causing the
 *        car to move straight backward.
 * @param copy_u8speed Speed percentage. Valid range: 0 (stopped) to 100 (max speed).
 * @return None
 */
void DCMOTOR_voidReverse(u8 copy_u8speed);

/**
 * @brief Turns the car left by stopping the left motor while driving
 *        the right motor forward (pivot turn).
 * @param copy_u8speed Speed percentage. Valid range: 0 (stopped) to 100 (max speed).
 * @return None
 */
void DCMOTOR_voidLeft(u8 copy_u8speed);

/**
 * @brief Turns the car right by stopping the right motor while driving
 *        the left motor forward (pivot turn).
 * @param copy_u8speed Speed percentage. Valid range: 0 (stopped) to 100 (max speed).
 * @return None
 */
void DCMOTOR_voidRight(u8 copy_u8speed);

/**
 * @brief Stops both motors immediately (IN1=IN2=0 for both motors,
 *        i.e. free-running stop, not active braking).
 * @param copy_u8speed Speed percentage. Valid range: 0 (stopped) to 100 (max speed).
 * @return None
 */
void DCMOTOR_voidStop(u8 copy_u8speed);

#endif /* DCMOTOR_INTERFACE_H_ */
