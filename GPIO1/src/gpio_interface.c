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


