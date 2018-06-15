#ifndef _LCD_Library_H_
#define  _LCD_Library_H_


//following macros are defined here, letter define these on the application file
#define LCD_Enable_PORT GPIO_PORT_A
#define LCD_Enable_PIN	0

#define LCD_RW_PORT	GPIO_PORT_A
#define LCD_RW_PIN 1

#define LCD_ModeSelect_PORT GPIO_PORT_A
#define LCD_ModeSelect_PIN 2

#define LCD_D0_PORT GPIO_PORT_A
#define LCD_D0_PIN 3

#define LCD_D1_PORT GPIO_PORT_A
#define LCD_D1_PIN 4

#define LCD_D2_PORT GPIO_PORT_A
#define LCD_D2_PIN 5

#define LCD_D3_PORT GPIO_PORT_A
#define LCD_D3_PIN 6

#define LCD_D4_PORT GPIO_PORT_A
#define LCD_D4_PIN 7

#define LCD_D5_PORT GPIO_PORT_A
#define LCD_D5_PIN 8

#define LCD_D6_PORT GPIO_PORT_A
#define LCD_D6_PIN 11

#define LCD_D7_PORT GPIO_PORT_A
#define LCD_D7_PIN 12

#define F_CPU 16000000

#include "gpio_interface.h"
#include <stdint.h>
//gpio_port_conf_data *gpio_lcd_config_data;

typedef struct{

	GPIORegister_structure *LCDX_port;
	uint8_t LCDX_pin;
}LCD_configStruct;

//Macros definition
//Define these macros in your program at the top

#define LCD_WRITE_MODE		0x00
#define LCD_READ_MODE		0x01
#define LCD_COMMAND_MODE	0x00
#define LCD_DATA_MODE		0x01
#define LCD_LATCH_ENABLE	0x01

/*
#ifndef LCD_COMMUNICATION_MODE
# warning "LCD Communication mode not defined, the default mode is 8-bit"
#define LCD_COMMUNICATION_MODE LCD_MODE_A
#endif
//future work needed to set the data communication mode

#ifndef LCD_DATA_PORT
# warning "LCD_DATA_PORT Not defined, the program will not work"
#define LCD_DATA_PORT GPIO_PORT_B
#endif
  
#ifndef	LCD_CONTROL_PORT
# warning "LCD_CONTROL_PORT not defined, the program will not work"
#define LCD_CONTROL_PORT GPIO_PORT_D
#endif

#ifndef LCD_RWPin
# warning "LCD_RWPin pin not defined"
#define LCD_RWPin 1
#endif

#ifndef LCD_ModeSelectPin
# warning "LCD_ModeSelectPin not defined"
#define LCD_ModeSelectPin 2
#endif

#ifndef LCD_EnablePin
# warning "LCD_EnablePin not defined"
#define LCD_EnablePin 3
#endif
*/



//Functions Declarations

/**********************************************************************************************************************************************
	
							User exposed API for accssing the Alphanumeric LCD library
	
***********************************************************************************************************************************************/	

	/**			LCD initialization functions
	*	@brief	This function initialize LCD after power up
				It sets the lcd for the AXB size matrix
				It also sets the data communication mode, i.e 4bit or 8bit mode 
	*	@param	None
	*	@retval	None
	*	@Constraints: After power up, wait atleast 15ms before initializing the LCD
	*/     
vPORTx createLCDPort();

void apiLCD_initializeLCD();


/**					Clear the LCD screen
	*	@brief	This function clears the LCD and puts cursor to (0,0) 
	*	@param	None
	*	@retval None
	*	@Constraints: Execution time (when FCP/FOSC is 250kHz) for clear display
	*				  command is 1.64ms. The time decreases at higher frequency
	*				  Look LCD datasheets for reference.
	*/
void apiLCD_clear_screen();

	
/**					Makes the display off
	*	@brief	This function makes the display screen off, 
				but the data sent to it for display is not lost 
	*	@param	None
	*	@retval None
	*/
void apiLCD_display_screenOFF();


/**					Makes the display screen on 
	*	@brief	This function makes the display screen on, 
				previously stored data is displayed on screen. 
	*	@param	None
	*	@retval None
	*/
void apiLCD_display_screenON();

	
	
/**
	*	@brief	This module is used to send the character to display on 
				LCD screen at current cursor position
	*	@param	LCDcharacter:	User desired character to be displayed on 
				the LCD screen at current cursor position
	*	@retval	None
	*/
	
void apiLCD_send_character(char LCDcharacter);


/**
	*	@brief	This function is used to send the string to display on the LCD screen
	*	@param	LCDstring:	This is the string that is to be displayed on the LCD screen
							at current cursor position
	*	@retval	None
	*/
void apiLCD_send_string(char *LCDstring);


/**
	*	@brief	This function is used to send the numerical values to the LCD
				Numbers can be directly sent to the LCD as a string using send string function
				But to send the numeric data from sensors we use this function.
	*	@param	LCDnumber:	The numeric value to be displayed on the screen.
	*	@retval	None
	*/
void apiLCD_send_number(int LCDnumber);

/**
	*	@brief	This function is used to position the cursor at desired position on LCD screen
	*	@param	x:	The cursor position along the row from the left side
					For 20X4 LCD the x can have value from 0 to 20.
	*	@param	y:	The cursor position along the column from the top
					For 20X4 LCD the y can have value from 0 to 4
	*	@retval	None
	*/
	
void apiLCD_set_coursertoXY(unsigned int x, unsigned int y);

#endif
