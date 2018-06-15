/*
 * gpio_interface.h
 *
 *  Created on: Jun 13, 2018
 *      Author: bichar4
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#include "port_struct.h"
#include "stm32f1xx_hal.h"

/********************************For virtual Port***********************/

typedef struct{
	GPIORegister_structure *Port_name;
	uint8_t Pin_number;
}vPort_comp;

typedef struct{
	vPort_comp vPortElement[8];
}vPORTx;

/**************************Virtual Port End**************************/

//Macros

#define GPIO_PIN_INPUT_MODE_PULLUP 0x8

/*****************/

vPORTx create_virtual_port(vPort_comp *vportcomponentstruct[]);

void write_vPort(vPORTx *VPORTX, uint8_t data);

void configure_gpio_port(GPIORegister_structure *GPIOX, uint32_t lower_pins_mode, uint32_t higher_pins_mode);
void write_gpio_port(GPIORegister_structure *GPIOX, uint16_t output_value);
uint16_t read_gpio_port(GPIORegister_structure *GPIOx);

void configure_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t pin_mode);

uint8_t read_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number);

void write_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t output_value);

void enable_gpio_clock(uint8_t GPIO_PORT_Number);

__weak void delay_ms(uint32_t Delay);

void incTick();
uint32_t  getTick();

#endif /* GPIO_INTERFACE_H_ */
