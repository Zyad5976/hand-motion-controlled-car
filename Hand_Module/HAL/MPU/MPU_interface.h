/*
 * MPU_interface.h
 *
 * Created: 8/14/2026 8:58:54 AM
 *  Author: Eltawel
 */ 


#ifndef MPU_INTERFACE_H_
#define MPU_INTERFACE_H_

/**
 * @brief Initializes the MPU6050: wakes it up from sleep mode and
 *        sets the accelerometer full-scale range as configured in
 *        MPU_CFG.h. Must be called once, after TWI_voidMasterInit().
 * @param None
 * @return None
 */
void MPU_voidInit(void);

/**
 * @brief Reads the raw 16-bit accelerometer value for the X axis.
 * @param None
 * @return s16 Raw signed accelerometer reading (X axis).
 */
s16 MPU_s16GetRawAccelX(void);

/**
 * @brief Reads the raw 16-bit accelerometer value for the Y axis.
 * @param None
 * @return s16 Raw signed accelerometer reading (Y axis).
 */
s16 MPU_s16GetRawAccelY(void);

/**
 * @brief Reads the raw 16-bit accelerometer value for the Z axis.
 * @param None
 * @return s16 Raw signed accelerometer reading (Z axis).
 */
s16 MPU_s16GetRawAccelZ(void);

#endif /* MPU_INTERFACE_H_ */