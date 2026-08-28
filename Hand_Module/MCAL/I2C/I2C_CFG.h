/*
 * I2C_CFG.h
 *
 * Created: 8/14/2026 9:00:43 AM
 *  Author: Eltawel
 */ 


#ifndef I2C_CFG_H_
#define I2C_CFG_H_

#include "../../LIB/Platform_CFG.h"

/* TWI Prescaler */
#define TWI_PRESCALER_1			0
#define TWI_PRESCALER_4			1
#define TWI_PRESCALER_16		2
#define TWI_PRESCALER_64		3

/* Select Prescaler */
#define TWI_PRESCALER			TWI_PRESCALER_1

/* TWBR_REG	Val */
//SCL_FREQUENCY = CPU_CLK_FREQ / (16 + 2*(TWBR_REG)*4^TWPS)

#define TWI_SCL_FREQ			400000UL

#define TWI_TWBR_VAL			(u8)(((F_CPU / TWI_SCL_FREQ) - 16) / 2)

#endif /* I2C_CFG_H_ */