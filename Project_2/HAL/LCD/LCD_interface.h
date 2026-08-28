/*
 * LCD_interface.h
 *
 * Created: 8/8/2026 5:35:06 PM
 *  Author: Eltawel
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/**
 * @brief Initializes the LCD in 4-bit mode according to the standard
 *        HD44780 initialization sequence (function set, display ON,
 *        clear display, entry mode set), using pin configuration
 *        defined in LCD_CFG.h.
 * @param None
 * @return None
 * @note Relies on TIM0_voidDelayMs() for the required timing delays
 *       between initialization steps.
 */
void LCD_voidInit(void);

/**
 * @brief Sends a command byte to the LCD (e.g. clear display, cursor
 *        home, display ON/OFF...). Internally splits the byte into
 *        two 4-bit nibbles since the driver operates in 4-bit mode.
 * @param copy_u8command Command byte, as defined by the HD44780 command set.
 * @return None
 */
void LCD_voidSendCommand(u8 copy_u8command);

/**
 * @brief Sends a single character of data to be displayed at the
 *        current cursor position.
 * @param copy_u8data ASCII character to display.
 * @return None
 */
void LCD_voidSendData(u8 copy_u8data);

/**
 * @brief CLear the LCD from any data to displayed nothing
 * @param none
 * @return None
 */
void LCD_voidClear();

/**
 * @brief Sends a null-terminated string to be displayed starting at
 *        the current cursor position.
 * @param copy_pu8string Pointer to a null-terminated character array (string).
 * @return None
 */
void LCD_voidSendString(u8 *copy_pu8string);

/**
 * @brief Converts a numeric value to its ASCII representation and
 *        displays it at the current cursor position.
 * @param copy_u32num Number to display.
 * @return None
 */
void LCD_voidSendNum(u32 copy_u32num);

/**
 * @brief Moves the LCD cursor to a specific row and column position.
 * @param copy_u8x Column position (0-based).
 * @param copy_u8y Row position (0-based, e.g. 0 = first row, 1 = second row).
 * @return None
 */
void LCD_voidGotoXY(u8 copy_u8x, u8 copy_u8y);

/**
 * @brief Stores a custom character pattern (e.g. a special icon) into
 *        the LCD's CGRAM and displays it at the given position.
 * @param copy_parr    Pointer to an 8-byte array defining the custom
 *                      character bitmap (5x8 pixel pattern).
 * @param copy_u8pattern CGRAM pattern slot index (0-7).
 * @param copy_u8x     Column position to display the character at.
 * @param copy_u8y     Row position to display the character at.
 * @return None
 */
void LCD_voidDisplayGraphicalData(u8 *copy_parr, u8 copy_u8pattern, u8 copy_u8x, u8 copy_u8y);

#endif /* LCD_INTERFACE_H_ */