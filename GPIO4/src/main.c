
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"


int main(void)
{
  HAL_Init();
  enable_gpio_clock(GPIO_CLOCK_C);

  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);



  while (1)
  {
	  write_gpio_pin(GPIO_PORT_C,13,1);
	  delay_ms(50);
	  write_gpio_pin(GPIO_PORT_C,13,0);
	  delay_ms(50);

 }

}


