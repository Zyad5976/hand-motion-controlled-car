/*
 * UART_prog.c
 *
 * Created: 8/7/2026 9:47:12 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/Platform_CFG.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_CFG.h"
#include "UART_interface.h"
#include "UART_REG.h"


void UART_voidInit(void)
{
	/* 1- Set UART Baud Rate : 9600 */
		UBRRL_REG = (u8)UBRR_VALUE;
		
	/* 2- Character Size --> 8 bit */
		UCSRC_REG = 0x86;
		
	/* 3- TX & RX Enbale */
		SET_BIT(UCSRB_REG, TXEN_BIT);
		SET_BIT(UCSRB_REG, RXEN_BIT);
}

void UART_voidSendData(u8 copy_u8data)
{
	/* 1- Storage data in UDR_REG */
		UDR_REG = copy_u8data;
		
	/* 2- Polling */
		while(GET_BIT(UCSRA_REG, UDRE_BIT) == 0);
}

u8 UART_u8ReceiveData(void)
{
	while(GET_BIT(UCSRA_REG, RXC_BIT) == 0);
	return UDR_REG;
}