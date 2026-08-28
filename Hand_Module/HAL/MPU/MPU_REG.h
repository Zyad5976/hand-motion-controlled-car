/*
 * MPU_REG.h
 *
 * Created: 8/21/2026 10:53:35 PM
 *  Author: Eltawel
 */ 


#ifndef MPU_REG_H_
#define MPU_REG_H_

/* I2C Address */
#define MPU6050_ADDRESS			0x68			// AD0 == LOW

/************************************************************************/
/*                             Registers                                */
/************************************************************************/


#define PWR_MGMT				0x6B
#define WHO_AM_I				0x75
#define ACCEL_CONFIG			0x1C

#define X_HIGH					0x3B
#define X_LOW					0x3C
#define Y_HIGH					0x3D
#define Y_LOW					0x3E
#define Z_HIGH					0x3F
#define Z_LOW					0x40

/************************************************************************/
/*                             Registers Bits                           */
/************************************************************************/

/* PWR_MGMT Bits */
#define DEVICE_RESET_BIT		7
#define SLEEP_BIT				6
#define CYCLE_BIT				5
#define TEMP_DIS_BIT			3
#define CLKSEL_2_BIT			2
#define CLKSEL_1_BIT			1
#define CLKSEL_0_BIT			0

/* ACCEL_CONFIG Bits */
#define XA_ST_BIT				7
#define YA_ST_BIT				6
#define ZA_ST_BIT				5
#define AFS_SEL1_BIT			4
#define AFS_SEL0_BIT			3

#endif /* MPU_REG_H_ */