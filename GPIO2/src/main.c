
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"



int main(void)
{
  HAL_Init();
  enable_gpio_clock(GPIO_CLOCK_C);




 GPIO_PORT_A->ConfigRegLow = GPIO_PORT_A->ConfigRegLow  | 0x00100000;
//todo Config pin 13 of port C as output using its pointer to structure

  while (1)
  {
	  //TODO Toggle the output of pin 13 port C
	  //by accessing its pointer structure

 }

}


