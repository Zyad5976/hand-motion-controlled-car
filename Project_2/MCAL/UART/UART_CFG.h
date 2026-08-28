/*
 * UART_CFG.h
 *
 * Created: 8/8/2026 2:53:24 AM
 *  Author: Eltawel
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

/* Includes */
#include "../../LIB/Platform_CFG.h"

/* Macros */
#define UART_BAUD		9600UL
#define UBRR_VALUE		((F_CPU/(16UL*UART_BAUD)) - 1)


#endif /* UART_CFG_H_ */