#include "port_struct.h"

void configure_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t pin_mode){

	if(pin_number < 8){
		GPIOX->ConfigRegLow = ( GPIOX->ConfigRegLow & ( ~ ( 1<< pin_number ) ) ) | (pin_mode << pin_number );

	}
	else{
		pin_number = pin_number - 8;
		GPIOX->ConfigRegLow = ( GPIOX->ConfigRegLow & ( ~ ( 1<< pin_number ) ) ) | (pin_mode << pin_number );
	}
}

uint8_t read_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number){

	return( ( GPIOX->InputDataReg >> pin_number ) & 0x01 );
}

void write_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t output_value){

	GPIOX->OutputDatareg = ( GPIOX->OutputDatareg & ( ~ ( 1<<pin_number ) ) ) | ( output_value << pin_number );
}

//Function for writing to GPIOx_Output_Register

void write_gpio_port(GPIORegister_structure *GPIOX, uint8_t, uint8_t output_value){

        GPIOX->OutputDatareg = ( GPIOX->OutputDatareg  | output_value );
}

//Function for reading GPIOx_Input_Register

uint16_t read_gpio_port(GPIORegister_structure *GPIOX){
 
        return( GPIOX->InputDataReg );
}

void enable_gpio_clock(uint8_t GPIO_PORT_Number){

    RCC->APB2ENR |= ( 1 << ( GPIO_PORT_Number + 2) );
}


