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
uint8_t pressed_key;
void api_gpio_config_for_keypad()
{

	for(int count = 0; count < NUMBER_OF_ROWS; count++)
	{

		configure_gpio_pin(KEYPAD_PORT, RowMatrix[count], 1);
	}

	for(int i = 0; i < NUMBER_OF_ROWS; i++)
		{
			write_gpio_pin(KEYPAD_PORT, RowMatrix[i], 0);
		}

	for (int count = 0; count < NUMBER_OF_COLUMN; count++)
	{

		configure_gpio_pin(KEYPAD_PORT, ColumnMatrix[count], 0x8);

	}
}

uint8_t api_scan_keypad()
{
//	for(int i = 0; i < NUMBER_OF_ROWS; i++)
//	{
//		write_gpio_pin(KEYPAD_PORT, RowMatrix[i], 1);
//	}

	uint8_t pinvalue=0;
	//uint8_t pressed_key;
	for(int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		write_gpio_pin(KEYPAD_PORT, RowMatrix[row], 1);
		int column = 0;
		do
		{
			pinvalue = read_gpio_pin(KEYPAD_PORT, ColumnMatrix[column]);
			column +=1; 
			
		} while ( ( (pinvalue != 0x01) && (column != NUMBER_OF_COLUMN ) ) );
		
		write_gpio_pin(KEYPAD_PORT, RowMatrix[row], 0);
		if( pinvalue == 0x01)
		{
			column = column - 1;
			pressed_key = KeypadMatrix[row][column];
			row = NUMBER_OF_ROWS;
		}
	}
	return pressed_key;
	//return 0;
}
