/*
 * I2C_prog.c
 *
 * Created: 8/14/2026 9:01:18 AM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "I2C_REG.h"
#include "I2C_CFG.h"
#include "I2C_interface.h"

void TWI_voidMasterInit(void)
{
	/* Set Bit Rate Register */
		TWBR_REG = TWI_TWBR_VAL;
		
	/* Set Prescaler */
		TWSR_REG = (TWSR_REG & 0xFC) | TWI_PRESCALER;
		
	/* TWI Enable Bit */
		SET_BIT(TWCR_REG, TWEN_BIT);
}

void TWI_voidMasterSendStart(void)
{
	/* Set TWI Interrupt Falg | Set TWI Start Condition | Set TWI Enable */
		TWCR_REG = (1 << TWINT_BIT) | (1 << TWSTA_BIT) | (1 << TWEN_BIT);
		
	/* Polling on Flag */
		while(GET_BIT(TWCR_REG, TWINT_BIT) == 0);
}

void TWI_voidMasterSendStop(void)
{
	/* Set TWI Interrupt Falg | Set TWI Stop Condition | Set TWI Enable */
		TWCR_REG = (1 << TWINT_BIT) | (1 << TWSTO_BIT) | (1 << TWEN_BIT);
}

void TWI_voidMasterWriteByte(u8 copy_u8data)
{
	/* Send Data */
		TWDR_REG = copy_u8data;
		
	/* Set TWI Interrupt Falg | Set TWI Enable */
		TWCR_REG = (1 << TWINT_BIT) | (1 << TWEN_BIT);
		
	/* Polling on Flag */
		while(GET_BIT(TWCR_REG, TWINT_BIT) == 0);
}

u8 TWI_u8MasterReadByteWithACK(void)
{
	u8 Loc_Val = 0;
	
	/* Set TWI Interrupt Falg | Enable ACK Bit | Set TWI Enable */
		TWCR_REG = (1 << TWINT_BIT) | (1 << TWEA_BIT) | (1 << TWEN_BIT);
		
	/* Polling on Flag */
		while(GET_BIT(TWCR_REG, TWINT_BIT) == 0);
		
	Loc_Val = TWDR_REG;
	
	return Loc_Val;
}

u8 TWI_u8MasterReadByteWithNACK(void)
{
	u8 Loc_Val = 0;
	
	/* Set TWI Interrupt Falg | Set TWI Enable */
		TWCR_REG = (1 << TWINT_BIT) | (1 << TWEN_BIT);
	
	/* Polling on Flag */
		while(GET_BIT(TWCR_REG, TWINT_BIT) == 0);
	
	Loc_Val = TWDR_REG;
	
	return Loc_Val;
}

u8 TWI_u8MasterGetStatus(void)
{
	u8 Loc_Status = 0;
		
	Loc_Status = (TWSR_REG & 0xF8);
	
	return Loc_Status;
}