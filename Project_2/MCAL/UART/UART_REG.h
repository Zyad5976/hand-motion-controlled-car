/*
 * UART_CFG.h
 *
 * Created: 8/7/2026 9:46:39 PM
 *  Author: Eltawel
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_

#define UDR_REG						*((volatile u8 *)0x2C)

#define UCSRA_REG					*((volatile u8 *)0x2B)

#define UCSRB_REG					*((volatile u8 *)0x2A)

#define UCSRC_REG					*((volatile u8 *)0x40) /* UCSRC_REG & UBRRH */

#define UBRRL_REG					*((volatile u8 *)0x29)



/* UCSRA_REG Bits */
#define RXC_BIT						7	/* UART Receive Complete */
#define TXC_BIT						6	/* UART Transmit Complete */
#define UDRE_BIT					5	/* UART Data Register Empty */
#define FE_BIT						4	/* Frame Error */
#define DOR_BIT						3	/* Data OverRun */
#define PE_BIT						2	/* Parity Error */
#define U2X_BIT						1	/* Double The UART Transmission Speed */
#define MPCM_BIT					0	/* Muli-Processor Communication Mode */

/* UCSRB_REG Bits */
#define RXCIE_BIT			7	/* RX Complete Interrupt Enable */
#define TXCIE_BIT			6	/* TX Complete Interrupt Enable */
#define UDRIE_BIT			5	/* UART Data Register Empty Interrupt Enable */
#define RXEN_BIT			4	/* Receiver Enable */
#define TXEN_BIT			3	/* Transmitter Enable */
#define UCSZ2_BIT			2	/* Character Size */
#define RXB8_BIT			1	/* Receive Data Bit 8 */
#define TXB8_BIT			0	/* Transmit Data Bit 8 */

/*UCSRC_REG Bits*/
#define URSEL_BIT			7	/* Register Select (UCSRC_REG OR UBRRL_REG) */
#define UCSZ1_BIT			2	/* Lock at UCSZ0_BIT */
#define UCSZ0_BIT			1	/* This Bits --> (UCSZ1_BIT & UCSZ0_BIT) Combiend with UCSZ2_BIT 
								    to Set The Numbers of Data Bits (Character Size) in a frame */

/*UBRRL_REG Bits*/
#define UBRR_BIT			12  /* UART Baud Rate Register */

#endif /* UART_REG_H_ */