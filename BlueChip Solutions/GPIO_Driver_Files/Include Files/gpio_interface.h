#ifndef __GPIO_INTERFACE_
#define __GPIO_INTERFACE_

#include "port_struct.h"

void configure_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t pin_mode);
uint8_t read_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number);
void write_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t output_value);
void write_gpio_port(GPIORegister_structure *GPIOX, uint16_t output_value);
uint16_t read_gpio_port(GPIORegister_structure *GPIOX);
void enable_gpio_clock(uint8_t GPIO_PORT_Number);

#endif
