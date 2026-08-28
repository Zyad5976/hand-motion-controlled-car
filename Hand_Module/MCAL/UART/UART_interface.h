/*
 * UART_interface.h
 *
 * Created: 8/7/2026 9:46:55 PM
 *  Author: Eltawel
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/**
 * @brief Initializes the USART peripheral (baud rate, frame format,
 *        enables transmitter and receiver) as configured in UART_Config.h.
 * @param None
 * @return None
 */
void UART_voidInit(void);

/**
 * @brief Sends a single byte of data over UART.
 *        Blocks until the data register is empty (UDRE flag set)
 *        before writing the new byte.
 * @param copy_u8data Byte to be transmitted.
 * @return None
 */
void UART_voidSendData(u8 copy_u8data);

/**
 * @brief Receives a single byte of data over UART.
 *        Blocks until a byte is fully received (RXC flag set).
 * @param None
 * @return u8 Received byte.
 */
u8 UART_u8ReceiveData(void);

#endif /* UART_INTERFACE_H_ */