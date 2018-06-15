#ifndef __KEYPAD_INTERFACE_API
#define __KEYPAD_INTERFACE_API

//#include "hal_gpio_driver.c"
//#include "max7219_7segments_api.h"
#include "gpio_interface.h"

//Define no of rows and the columns
#define NUMBER_OF_ROWS 4
#define NUMBER_OF_COLUMN 4
#define KEYPAD_PORT GPIO_PORT_B

//Defines pin for various rows and column of the key pad
#define ROW_1_PIN        3
#define ROW_2_PIN		4
#define ROW_3_PIN		5
#define ROW_4_PIN		6
#define COLUMN_1_PIN	7
#define COLUMN_2_PIN	8
#define COLUMN_3_PIN	9
#define COLUMN_4_PIN	10
//Define the keypad matrix
unsigned char check;

/*
unsigned char KeypadMatrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMN] = { 
																{1,2,3}, 
																{4,5,6},
																{7,8,9},
																{0,0,0} 
															   };
unsigned char ColumnMatrix[NUMBER_OF_COLUMN] = {COLUMN_1_PIN, COLUMN_2_PIN, COLUMN_3_PIN, COLUMN_4_PIN};
unsigned char RowMatrix[NUMBER_OF_ROWS] = {ROW_1_PIN, ROW_2_PIN, ROW_3_PIN, ROW_4_PIN};
*/

void api_gpio_config_for_keypad();
uint8_t api_scan_keypad();

#endif
