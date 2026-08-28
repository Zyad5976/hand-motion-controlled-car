/*
 * I2C_interface.h
 *
 * Created: 8/14/2026 9:00:55 AM
 *  Author: Eltawel
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

/**
 * @brief Initializes the TWI peripheral in Master mode: sets the SCL
 *        clock frequency (via TWBR and the prescaler configured in
 *        TWI_CFG.h) and enables the TWI hardware.
 *        Must be called once before any other TWI_Master function.
 * @param None
 * @return None
 */
void TWI_voidMasterInit(void);

/**
 * @brief Sends a START (or Repeated START) condition on the bus,
 *        marking the beginning of a new I2C transaction (or a
 *        direction change within the same transaction, e.g. switching
 *        from writing a register address to reading its value).
 *        Blocking: waits for the TWINT flag before returning.
 * @param None
 * @return None
 */
void TWI_voidMasterSendStart(void);

/**
 * @brief Sends a STOP condition on the bus, marking the end of the
 *        current I2C transaction and releasing the bus for other
 *        potential masters.
 * @param None
 * @return None
 */
void TWI_voidMasterSendStop(void);

/**
 * @brief Writes a single byte to the bus and waits for the operation
 *        to complete. Used for the slave address+R/W byte, register
 *        addresses, and data bytes alike.
 *        Blocking: waits for the TWINT flag before returning.
 * @param copy_u8data Byte to be transmitted (e.g. SLA+W, SLA+R,
 *                     register address, or a data byte).
 * @return None
 */
void TWI_voidMasterWriteByte(u8 copy_u8data);

/**
 * @brief Reads a single byte from the bus and responds with an ACK,
 *        signaling the slave that more bytes are expected to follow
 *        in this read sequence.
 *        Blocking: waits for the TWINT flag before returning.
 * @param None
 * @return u8 The byte read from the bus.
 */
u8 TWI_u8MasterReadByteWithACK(void);

/**
 * @brief Reads a single byte from the bus and responds with a NACK,
 *        signaling the slave that this is the last byte expected,
 *        ending the read sequence.
 *        Blocking: waits for the TWINT flag before returning.
 * @param None
 * @return u8 The byte read from the bus.
 */
u8 TWI_u8MasterReadByteWithNACK(void);

/**
 * @brief Returns the current TWI status code (upper 5 bits of TWSR,
 *        with the prescaler bits masked out). Used after each TWI
 *        operation to verify it completed as expected before
 *        proceeding to the next step.
 * @param None
 * @return u8 Status code, to be compared against values defined in
 *            TWI_REG.h (e.g. START_CONDITION, SEND_DATA_WITH_ACK).
 */
u8 TWI_u8MasterGetStatus(void);

#endif /* I2C_INTERFACE_H_ */