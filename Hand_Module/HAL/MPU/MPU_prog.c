/*
 * MPU_prog.c
 *
 * Created: 8/14/2026 8:59:09 AM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/I2C/I2C_interface.h"
#include "MPU_REG.h"
#include "MPU_CFG.h"
#include "MPU_interface.h"


/**
 * @brief Internal helper that reads the raw 16-bit accelerometer value
 *        from a given axis register pair (High/Low bytes), following
 *        the standard MPU6050 read sequence: START, write device
 *        address + register address, Repeated START, write device
 *        address for read, read High byte (ACK), read Low byte (NACK),
 *        STOP, then combine both bytes into one 16-bit signed value.
 *        Used internally by MPU_s16GetRawAccelX/Y/Z() to avoid
 *        duplicating this sequence three times.
 * @param copy_u8RegisterAddress The "High byte" register address for
 *                                the desired axis (e.g. X_HIGH, Y_HIGH,
 *                                or Z_HIGH from MPU_REG.h). The Low
 *                                byte is assumed to be the next
 *                                register address (auto-incremented
 *                                by the sensor).
 * @return s16 The combined signed 16-bit raw reading for that axis.
 */
static s16 MPU_s16ReadAxisRaw(u8 copy_u8RegisterAddress)
{
	u8 Loc_High = 0;
	u8 Loc_Low = 0;
	s16 Loc_val = 0;
	
	TWI_voidMasterSendStart();
	
	TWI_voidMasterWriteByte(MPU6050_ADDRESS << 1);
	
	TWI_voidMasterWriteByte(copy_u8RegisterAddress);
	
	TWI_voidMasterSendStart();
	
	TWI_voidMasterWriteByte(1 | (MPU6050_ADDRESS << 1));
	
	Loc_High = TWI_u8MasterReadByteWithACK();
	
	Loc_Low = TWI_u8MasterReadByteWithNACK();
	
	TWI_voidMasterSendStop();
	
	Loc_val = (Loc_High << 8) | Loc_Low;
	
	return Loc_val;
}


void MPU_voidInit(void)
{
	/* Wake up the device */
	/* Start Condition */
		TWI_voidMasterSendStart();
		
	/* send data to mpu address */
		TWI_voidMasterWriteByte(MPU6050_ADDRESS << 1);
		
	/* send data to pwr mgmnt */
		TWI_voidMasterWriteByte(PWR_MGMT);
		
	/* clear sleep mode */
		TWI_voidMasterWriteByte(0x00);
		
	/* send stop */
		TWI_voidMasterSendStop();
		
	/* Set ACC Full Scale Range */
		
	/* Start Condition */
		TWI_voidMasterSendStart();
	
	/* send data to mpu address */
		TWI_voidMasterWriteByte(MPU6050_ADDRESS << 1);
		
	/* Set Accel config */
		TWI_voidMasterWriteByte(ACCEL_CONFIG);
	
	/* Set MPU Range */
	TWI_voidMasterWriteByte(MPU_RANGE << AFS_SEL0_BIT);
	
	/* send stop */
		TWI_voidMasterSendStop();
}

s16 MPU_s16GetRawAccelX(void)
{
	return MPU_s16ReadAxisRaw(X_HIGH);
}

s16 MPU_s16GetRawAccelY(void)
{
	return MPU_s16ReadAxisRaw(Y_HIGH);
}

s16 MPU_s16GetRawAccelZ(void)
{
	return MPU_s16ReadAxisRaw(Z_HIGH);
}