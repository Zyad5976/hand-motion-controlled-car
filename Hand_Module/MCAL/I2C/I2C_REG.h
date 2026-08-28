/*
 * I2C_REG.h
 *
 * Created: 8/14/2026 9:00:28 AM
 *  Author: Eltawel
 */ 


#ifndef I2C_REG_H_
#define I2C_REG_H_

/************************************************************************/
/*                                REGISTERS                             */
/************************************************************************/

#define TWBR_REG				*((volatile u8*)0x20)		/* [7:0] TWI Bit Rate Register */
#define TWCR_REG				*((volatile u8*)0x56)		/* TWI Control Register */
#define TWSR_REG				*((volatile u8*)0x21)		/* Status Register */
#define TWDR_REG				*((volatile u8*)0x23)		/* [7:0] TWI Data Register */
#define TWAR_REG				*((volatile u8*)0x22)		/* [7:1] TWI Slave Address Register */


/* Register Bits */

/* TWCR_REG Bits */
#define TWINT_BIT			7		/* TWI Interrupt Flag */
#define TWEA_BIT			6		/* TWI Enable ACK Bit */
#define TWSTA_BIT			5		/* TWI Start Condition Bit */
#define TWSTO_BIT			4		/* TWI Stop Condition Bit */
#define TWWC_BIT			3		/* TWI Write Collision Flag */
#define TWEN_BIT			2		/* TWI Enable Bit */
#define TWIE_BIT			0		/* TWI Interrupt Flag */

/*				   Bit (1) Reserved					  */

/* TWSR_REG Bits */
#define TWS_BIT7				7		/* TWI Status */
#define TWS_BIT6				6		/* TWI Status */
#define TWS_BIT5				5		/* TWI Status */
#define TWS_BIT4				4		/* TWI Status */
#define TWS_BIT3				3		/* TWI Status */
#define TWPS_BIT1				1		/* TWI Prescaler Bit */
#define TWPS_BIT0				0		/* TWI Prescaler Bit */

/*				   Bit (2) Reserved					  */

/************************************************************************/
/*              Status Code for Master Transmitter Mode                 */
/************************************************************************/

// #define START_CONDITION					0x08
// #define REPEATED_START_CONDITION			0x10
// #define SEND_ACK							0x18
// #define SEND_NOT_ACK						0x20
// #define SEND_DATA_WITH_ACK				0x28
// #define SEND_DATA_WITH_NOT_ACK			0x30
// #define ARBITRATION_LOST					0x38
// #define STOP_CONDITION					0xA0

#endif /* I2C_REG_H_ */