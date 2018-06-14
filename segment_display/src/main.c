
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"


static void MX_GPIO_Init(void);


int main(void)
{
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
  configure_gpio_pin(GPIO_PORT_A,1,0x0001);
  configure_gpio_pin(GPIO_PORT_A,2,0x0001);
  configure_gpio_pin(GPIO_PORT_A,3,0x0001);
  configure_gpio_pin(GPIO_PORT_A,4,0x0001);
  configure_gpio_pin(GPIO_PORT_A,5,0x0001);
  configure_gpio_pin(GPIO_PORT_A,6,0x0001);
  configure_gpio_pin(GPIO_PORT_A,7,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);


  while (1)
  {
	  write_gpio_pin(GPIO_PORT_A,0,0);
	  write_gpio_pin(GPIO_PORT_A,1,0);
	  write_gpio_pin(GPIO_PORT_A,2,0);
	  write_gpio_pin(GPIO_PORT_A,3,0);
	  write_gpio_pin(GPIO_PORT_A,4,0);
	  write_gpio_pin(GPIO_PORT_A,5,0);
	  write_gpio_pin(GPIO_PORT_A,6,0);
	  write_gpio_pin(GPIO_PORT_A,7,0);

	  write_gpio_pin(GPIO_PORT_C,13,1);
	  delay_ms(500);
	  write_gpio_pin(GPIO_PORT_C,13,0);
	  write_gpio_pin(GPIO_PORT_A,0,1);
	  write_gpio_pin(GPIO_PORT_A,1,1);
	  write_gpio_pin(GPIO_PORT_A,2,1);
	  write_gpio_pin(GPIO_PORT_A,3,1);
	  write_gpio_pin(GPIO_PORT_A,4,1);
	  write_gpio_pin(GPIO_PORT_A,5,1);
	  write_gpio_pin(GPIO_PORT_A,6,1);
	  write_gpio_pin(GPIO_PORT_A,7,1);
	  delay_ms(500);

 }
}
