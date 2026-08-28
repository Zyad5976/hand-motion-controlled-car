/*
 * LCD_CFG.h
 *
 * Created: 8/8/2026 5:34:57 PM
 *  Author: Eltawel
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/* LCD Control Port Dir */
#define LCD_CPORT_DIR			0x03

/* LCD Data Port Dir */
#define LCD_DPORT_DIR			0xF0

/* LCD Control PORT */
#define LCD_CPORT				DIO_PORTB

/* LCD Contrl Pins */
#define LCD_RS_PIN				DIO_PIN0
//#define LCD_RW_PIN			GND
#define LCD_E_PIN				DIO_PIN1

/* LCD Data PORT */
#define LCD_DPORT				DIO_PORTA

/* LCD Data Pins */
#define LCD_D4_PIN				DIO_PIN4
#define LCD_D5_PIN				DIO_PIN5
#define LCD_D6_PIN				DIO_PIN6
#define LCD_D7_PIN				DIO_PIN7

/* LCD Bits */
#define LCD_4_BIT				4


#endif /* LCD_CFG_H_ */