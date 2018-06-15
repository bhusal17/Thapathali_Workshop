#include "api_lcd_driver.h"


LCD_configStruct LCD_configMatrix[11]={
		{LCD_Enable_PORT,LCD_Enable_PIN},
		{LCD_RW_PORT,LCD_RW_PIN},
		{LCD_ModeSelect_PORT,LCD_ModeSelect_PIN},
		{LCD_D0_PORT,LCD_D0_PIN},
		{LCD_D1_PORT,LCD_D1_PIN},
		{LCD_D2_PORT,LCD_D2_PIN},
		{LCD_D3_PORT,LCD_D3_PIN},
		{LCD_D4_PORT,LCD_D4_PIN},
		{LCD_D5_PORT,LCD_D5_PIN},
		{LCD_D6_PORT,LCD_D6_PIN},
		{LCD_D7_PORT,LCD_D7_PIN}
};




/**					Send command to LCD
	*	@brief	This function sends user command to LCD 
	*	@param	LCDcommand: The user desired command to LCD
	*	@retval None
	*	@Constraints: Execution time (when FCP/FOSC is 250kHz) for clear display
	*				  and return home command is 1.64ms. The time decreases at
	*				   higher frequency. Look LCD datasheets for other commands.
	*/
	
vPort_comp sevensegdiet[11]={
		{LCD_Enable_PORT,LCD_Enable_PIN},
		{LCD_RW_PORT,LCD_RW_PIN},
		{LCD_ModeSelect_PORT,LCD_ModeSelect_PIN},
		{LCD_D0_PORT,LCD_D0_PIN},
		{LCD_D1_PORT,LCD_D1_PIN},
		{LCD_D2_PORT,LCD_D2_PIN},
		{LCD_D3_PORT,LCD_D3_PIN},
		{LCD_D4_PORT,LCD_D4_PIN},
		{LCD_D5_PORT,LCD_D5_PIN},
		{LCD_D6_PORT,LCD_D6_PIN},
		{LCD_D7_PORT,LCD_D7_PIN}
};

vPORTx createLCDPort(){
	vPORTx LCDPort;
	vPort_comp *segdietout[8];
			for(uint8_t i=0; i<8; i++){
				segdietout[i]=&sevensegdiet[i];
			}
		  LCDPort = create_virtual_port(segdietout);
		  return LCDPort;
}

void localLCD_check_status(){

	//sets the dataport in input tristate mode
	for(uint8_t i=3; i<11; i++){
						configure_gpio_pin(LCD_configMatrix[i].LCDX_port,LCD_configMatrix[i].LCDX_pin,4);
			}

//
//	gpio_lcd_config_data.port_mode_type = GPIO_PORT_INPUT_MODE;
//	gpio_lcd_config_data.port_input_type = GPIO_PORT_INPUT_TYPE_TRISTATE;
//	//hal_gpio_port_setup(LCD_DATA_PORT, &gpio_lcd_config_data);

	gpio_write_pin(LCD_configMatrix[1].LCDX_port,LCD_configMatrix[1].LCDX_pin,0x01/*LCD Read Mode*/);
	gpio_write_pin(LCD_configMatrix[2].LCDX_port,LCD_configMatrix[2].LCDX_pin,LCD_COMMAND_MODE);

//	hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_RWPin, LCD_READ_MODE);
//	hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_ModeSelectPin, LCD_COMMAND_MODE);

	//uint8_t pinvalue = 1;
	//while( pinvalue == 1)
	//{
		//set lcd latch enable pin to high
	gpio_write_pin(LCD_configMatrix[0].LCDX_port,LCD_configMatrix[0].LCDX_pin,1);
	delay_ms(100);
	gpio_write_pin(LCD_configMatrix[0].LCDX_port,LCD_configMatrix[0].LCDX_pin,0);
//		hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_EnablePin, GPIO_PIN_OUTPUT_HIGH);
//		_delay_us(100);
//		hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_EnablePin, GPIO_PIN_OUTPUT_LOW);

	//pinvalue = hal_gpio_read_from_pin(LCD_DATA_PORT, PB7 );
	//}
	//set the LCD data port to output mode 
	

	for(uint8_t i=3; i<11; i++){
							configure_gpio_pin(LCD_configMatrix[i].LCDX_port,LCD_configMatrix[i].LCDX_pin,1);
				}

	gpio_write_pin(LCD_configMatrix[1].LCDX_port,LCD_configMatrix[1].LCDX_pin,LCD_WRITE_MODE);
	gpio_write_pin(LCD_configMatrix[2].LCDX_port,LCD_configMatrix[2].LCDX_pin,LCD_DATA_MODE);

	//	gpio_lcd_config_data.port_mode_type = GPIO_PORT_OUTPUT_MODE;
//	hal_gpio_port_setup(LCD_DATA_PORT, &gpio_lcd_config_data);
//	hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_RWPin, LCD_WRITE_MODE);
//	hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_ModeSelectPin, LCD_DATA_MODE);
}

/**					Send command to LCD
	*	@brief	This function sends user command to LCD 
	*	@param	LCDcommand: The user desired command to LCD
	*	@retval None
	*	@Constraints: Execution time (when FCP/FOSC is 250kHz) for clear display
	*				  and return home command is 1.64ms. The time decreases at
	*				   higher frequency. Look LCD datasheets for other commands.
	*/
void localLCD_send_command (uint8_t LCDcommand){
	
	localLCD_check_status();//at the end of this function lcd is in data write mode and data port in write mode

	gpio_write_pin(LCD_configMatrix[2].LCDX_port,LCD_configMatrix[2].LCDX_pin,LCD_COMMAND_MODE);

	write_vPort(LCDPort,LCDcommand);
	gpio_write_pin(LCD_configMatrix[2].LCDX_port,LCD_configMatrix[2].LCDX_pin,1);
	delay_ms(1);
	gpio_write_pin(LCD_configMatrix[2].LCDX_port,LCD_configMatrix[2].LCDX_pin,0);

	//	hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_ModeSelectPin, LCD_COMMAND_MODE);
	//hal_gpio_write_to_port(LCD_DATA_PORT, LCDcommand);
	//hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_EnablePin, GPIO_PIN_OUTPUT_HIGH);
	//_delay_us(1);
	//hal_gpio_write_to_pin(LCD_CONTROL_PORT, LCD_EnablePin, GPIO_PIN_OUTPUT_LOW);
	
}

//setups pins of the microcontroller to which lcd is connected
void localLCD_pins_setup(){

		LCD_configStruct lcd_pin_setup_data;
		//initializing the LCD pins
		for(uint8_t i=0; i<11; i++){
					configure_gpio_pin(LCD_configMatrix[i].LCDX_port,LCD_configMatrix[i].LCDX_pin,1);
		}
}
		
//Functions Definitions

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
void apiLCD_initializeLCD(){
	//future work:: write this function to accept the data for data mode, data length, cursor on/off
	
	
	localLCD_pins_setup();
	
//hal_gpio_write_to_port(LCD_DATA_PORT, LCDcommand);
	
	
	delay_ms(15);
	localLCD_send_command(0x38);	//This is the first command to lcd, it sets the data mode to 8 bit wit 2 display lines adnd 5*8 fonts
	delay_us(80);
	localLCD_send_command(0x0C);	// This command make the display on and cursor on, cursor blinking on
	delay_us(80);
	localLCD_send_command(0x01);	//this command clears the display and set cursor to 0,0
	delay_ms(2);
//	localLCD_send_command(0x02);
//	_delay_ms(2);
	
}


/**					Clear the LCD screen
	*	@brief	This function clears the LCD and puts cursor to (0,0) 
	*	@param	None
	*	@retval None
	*	@Constraints: Execution time (when FCP/FOSC is 250kHz) for clear display
	*				  command is 1.64ms. The time decreases at higher frequency
	*				  Look LCD datasheets for reference.
	*/
void apiLCD_clear_screen(){
	
	localLCD_send_command(0x01);
	delay_ms(2);
}


/**					Makes the display off
	*	@brief	This function makes the display screen off, 
				but the data sent to it for display is not lost 
	*	@param	None
	*	@retval None
	*/

void apiLCD_display_screenOFF(){
	
	localLCD_send_command(0x08);
}


/**					Makes the display screen on 
	*	@brief	This function makes the display screen on, 
				previously stored data is displayed on screen. 
	*	@param	None
	*	@retval None
	*/
void apiLCD_display_screenON(){
	
	localLCD_send_command(0x0E);
}
	

/**
	*	@brief	This module is used to send the character to display on 
				LCD screen at current cursor position
	*	@param	LCDcharacter:	User desired character to be displayed on 
				the LCD screen at current cursor position
	*	@retval	None
	*/
	
void apiLCD_send_character(char LCDcharacter){

	localLCD_check_status();
	write_vPort(LCDPort,LCDcharacter);
	//hal_gpio_write_to_port(LCD_DATA_PORT,LCDcharacter);
	gpio_write_pin(LCD_configMatrix[0].LCDX_port,LCD_configMatrix[0].LCDX_pin,1/*GPIO_PIN_OUTPUT_HIGH*/);
	delay_ms(1);
	gpio_write_pin(LCD_configMatrix[0].LCDX_port,LCD_configMatrix[0].LCDX_pin,1/*GPIO_PIN_OUTPUT_LOW*/);
}


/**
	*	@brief	This function is used to send the string to display on the LCD screen
	*	@param	LCDstring:	This is the string that is to be displayed on the LCD screen
							at current cursor position
	*	@retval	None
	*/
void apiLCD_send_string(char *LCDstring){
	
	while(*LCDstring != 0)
	{
		apiLCD_send_character(*LCDstring);
		LCDstring += 1;
	}	
}


/**
	*	@brief	This function is used to send the numerical values to the LCD
				Numbers can be directly sent to the LCD as a string using send string function
				But to send the numeric data from sensors we use this function.
	*	@param	LCDnumber:	The numeric value to be displayed on the screen.
	*	@retval	None
	*/
void apiLCD_send_number(int LCDnumber){
	
	char LCDstring[5];
	itoa(LCDnumber,LCDstring,10);
	apiLCD_send_string(LCDstring);
}

/**
	*	@brief	This function is used to position the cursor at desired position on LCD screen
	*	@param	x:	The cursor position along the row from the left side
					For 20X4 LCD the x can have value from 0 to 20.
	*	@param	y:	The cursor position along the column from the top
					For 20X4 LCD the y can have value from 0 to 4
	*	@retval	None
	*/
	
void apiLCD_set_coursertoXY(unsigned int x, unsigned int y){

	unsigned int LCD_firstColumn[] = {0x80,0xC0, 0x94, 0xD4};
	localLCD_send_command( LCD_firstColumn[y] + x );	
}
