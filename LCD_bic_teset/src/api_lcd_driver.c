#include "api_lcd_driver.h"

void LCD_Command (char cmd)							/* LCD command write function */
{
	//LCD_Data_Port = cmd;							/* Write command data to LCD data port */
	write_gpio_port(LCD_Data_Port,cmd);
	//LCD_Command_Port &= ~((1<<RS)|(1<<RW));			/* Make RS LOW (command reg.), RW LOW (Write) */
	write_gpio_pin(LCD_Command_Port,RS,0);
	write_gpio_pin(LCD_Command_Port,RW,0);

	//LCD_Command_Port |= (1<<EN);					/* High to Low transition on EN (Enable) */
	write_gpio_pin(LCD_Command_Port,EN,1);
	delay_ms(1);
	//LCD_Command_Port &= ~(1<<EN);
	write_gpio_pin(LCD_Command_Port,EN,0);
	delay_ms(3);									/* Wait little bit */
}

void LCD_Char (char char_data)						/* LCD data write function */
{
	//LCD_Data_Port = char_data;						/* Write data to LCD data port */
	write_gpio_port(LCD_Data_Port,char_data);
	//LCD_Command_Port &= ~(1<<RW);					/* Make RW LOW (Write) */
	write_gpio_pin(LCD_Command_Port,RW,0);

	//LCD_Command_Port |= (1<<EN)|(1<<RS);			/* Make RS HIGH (data reg.) and High to Low transition on EN (Enable) */
	write_gpio_pin(LCD_Command_Port,RS,1);
	write_gpio_pin(LCD_Command_Port,EN,1);
	delay_ms(1);
	//LCD_Command_Port &= ~(1<<EN);
	write_gpio_pin(LCD_Command_Port,EN,0);
	delay_ms(1);									/* Wait little bit */
}

void LCD_Init (void)								/* LCD Initialize function */
{
//	LCD_Command_Dir |= (1<<RS)|(1<<RW)|(1<<EN);		/* Make LCD command port direction as o/p */
	configure_gpio_pin(LCD_Command_Port,RS,0x001);
	configure_gpio_pin(LCD_Command_Port,RW,0x001);
	configure_gpio_pin(LCD_Command_Port,RS,0x001);
	
	//LCD_Data_Dir = 0xFF;							/* Make LCD data port direction as o/p */
	configure_gpio_port(LCD_Data_Port,0x1111,0x1111);
	delay_ms(20);									/* LCD power up time to get things ready, it should always >15ms */
	LCD_Command (0x38);								/* Initialize 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);								/* Display ON, Cursor OFF command */
	LCD_Command (0x06);								/* Auto Increment cursor */
	LCD_Command (0x01);								/* Clear LCD command */
	LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
}

void LCD_String (char *str)							/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)							/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);							/* Call LCD data write */
	}
}


void lcd_string_write(char *string)
{
	while (*string)
	LCD_Char(*string++);
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD function */
{
	if (row == 1)
		LCD_Command((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
	else if (row == 2)
		LCD_Command((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
	LCD_String(str);								/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command(0x01);								/* clear display */
}
