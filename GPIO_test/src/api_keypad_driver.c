#include "api_keypad_driver.h"

//
unsigned char KeypadMatrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMN] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
};
unsigned char ColumnMatrix[NUMBER_OF_COLUMN] = {COLUMN_1_PIN, COLUMN_2_PIN, COLUMN_3_PIN, COLUMN_4_PIN};
unsigned char RowMatrix[NUMBER_OF_ROWS] = {ROW_1_PIN, ROW_2_PIN, ROW_3_PIN, ROW_4_PIN};
	
	//

void api_gpio_config_for_keypad()
{
	gpio_pin_conf_t gpio_pin_confg_data_for_keypad;
	gpio_pin_confg_data_for_keypad.pin = ROW_1_PIN;
	for(int count = 0; count < NUMBER_OF_ROWS; count++)
	{

		configure_gpio_pin(KEYPAD_PORT, RowMatrix[count], 1);
	}
	for (int count = 0; count < NUMBER_OF_COLUMN; count++)
	{

		configure_gpio_pin(KEYPAD_PORT, ColumnMatrix[count], 0x8);

	}
}

unsigned char api_scan_keypad()
{
	for(int i = 0; i < NUMBER_OF_ROWS; i++)
	{	
		write_gpio_pin(KEYPAD_PORT, RowMatrix[i], 1);
	}
	uint8_t pinvalue=0;
	unsigned char pressed_key='X';
	for(int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		write_gpio_pin(KEYPAD_PORT, RowMatrix[row], 0);
		int column = 0;
		do
		{
			pinvalue = read_gpio_pin(KEYPAD_PORT, ColumnMatrix[column]);
			column +=1; 
			
		} while ( ( (pinvalue != 0x00) && (column != NUMBER_OF_COLUMN ) ) );
		
		write_gpio_pin(KEYPAD_PORT, RowMatrix[row], 1);
		if( pinvalue == 0x00)
		{
			column = column - 1;
			pressed_key = KeypadMatrix[row][column];
			row = NUMBER_OF_ROWS;
		}
	}
	return pressed_key;
}
