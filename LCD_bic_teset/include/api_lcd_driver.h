#ifndef _LCD_Library_H_
#define  _LCD_Library_H_


#include "gpio_interface.h"
#include "gpio_interface.h"


#define LCD_Data_Port GPIO_PORT_A				/* Define LCD data port */
#define LCD_Command_Port GPIO_PORT_C			/* Define LCD data port */
#define EN 15							/* Define Enable signal pin */
#define RW 14							/* Define Read/Write signal pin */
#define RS 13							/* Define Register Select (data reg./command reg.) signal pin */



void LCD_Command (char);				/* LCD command write function */
void LCD_Char (char);					/* LCD data write function */
void LCD_Init (void);					/* LCD Initialize function */
void LCD_String (char*);				/* Send string to LCD function */
void LCD_String_xy (char,char,char*);	/* Send row, position and string to LCD function */
void LCD_Clear();						/* Clear LCD*/
void lcd_string_write(char *string);

#endif
