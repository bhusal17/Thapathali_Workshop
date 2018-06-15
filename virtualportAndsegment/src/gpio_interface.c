/*
 * gpio_interface.c
 *
 *  Created on: Jun 13, 2018
 *      Author: bichar4
 */

//From Arjun

#include "gpio_interface.h"
#include "stm32f1xx_hal.h"

__IO uint32_t uwTICK;


vPORTx create_virtual_port(vPort_comp *vportcomponentstruct[]){
	vPORTx  virtualPort;
	for(uint8_t i=0; i< 8; i++){
		virtualPort.vPortElement[i].Port_name = vportcomponentstruct[i]->Port_name;
		virtualPort.vPortElement[i].Pin_number= vportcomponentstruct[i]->Pin_number;
	}
	return virtualPort;

}

void write_vPort(vPORTx *VPORTX, uint8_t data){

	for(uint8_t i=0; i<8; i++){
		VPORTX->vPortElement[i].Port_name->OutputDatareg =
				( ( VPORTX->vPortElement[i].Port_name->OutputDatareg /* previous data read */
				& ( ~ (1 << (VPORTX->vPortElement[i].Pin_number) )) ) /* Desired Pin masked */
				| ( ( ( data >> i ) & 0x01 ) << VPORTX->vPortElement[i].Pin_number) );/* data input gives has the value to be written to
				                                                           the virtual port pins, first the virtual port ith bit value is
				is shifted to the 0th positon and all other bits are made 0, then the 0th bit is shifted to the pinnumber of actual port */
	}

}



void configure_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t pin_mode){

	if(pin_number < 8){
		GPIOX->ConfigRegLow = ( GPIOX->ConfigRegLow & ( ~ ( 0xf<< (pin_number*4) ) ) ) | (pin_mode << (pin_number*4) );

	}
	else{
		pin_number = pin_number - 8;
		GPIOX->ConfigRegHigh = ( GPIOX->ConfigRegHigh & ( ~ ( 0xf<< (pin_number*4) ) ) ) | (pin_mode << (pin_number*4) );
	}
}

uint8_t read_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number){

	return( ( ( GPIOX->InputDataReg ) >> pin_number ) & 0x01 );
}

void write_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t output_value){

	GPIOX->OutputDatareg = ( GPIOX->OutputDatareg & ( ~ ( 1<<pin_number ) ) ) | ( output_value << pin_number );
}

void enable_gpio_clock(uint8_t GPIO_PORT_Number){

    RCC->APB2ENR |= ( 1 << ( GPIO_PORT_Number + 2) );
}

__weak void delay_ms(uint32_t Delay)
{
  uint32_t tickstart = getTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < 0xFFFFFFFFU)
  {
    wait += (uint32_t)(1U);
  }

  while ((getTick() - tickstart) < wait)
  {
  }
}
uint32_t  getTick(){
	return uwTICK;
}

void incTick(){
	uwTICK+=1U;
}


