
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"



int main(void)
{
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);

  //GPIO PIN Input function checking

  enable_gpio_clock(GPIO_CLOCK_B);
  configure_gpio_pin(GPIO_PORT_B,12,8);
  write_gpio_pin(GPIO_PORT_B, 12, 1);		//For enabling Input PullUp for PortB pin 11
  volatile uint16_t pinValue;
  while(1){
	  pinValue= read_gpio_pin(GPIO_PORT_B, 12);
	  if(pinValue == 1){
		  write_gpio_pin(GPIO_PORT_C,13,1);
	  }
	  else if(pinValue == 0){
		  write_gpio_pin(GPIO_PORT_C,13,0);
	  }
	  else
	  {
		  write_gpio_pin(GPIO_PORT_C,13,1);
		  delay_ms(50);
    	  write_gpio_pin(GPIO_PORT_C,13,0);
	 	  delay_ms(50);
	  }
  }

  //GPIO PIN Input function checking finish, the function is working

//  while (1)
//  {
////	  write_gpio_pin(GPIO_PORT_A,0,1);
////	  write_gpio_pin(GPIO_PORT_A,1,0);
////	  write_gpio_pin(GPIO_PORT_A,2,0);
//	  write_gpio_pin(GPIO_PORT_C,13,1);
//	  delay_ms(50);
//	  write_gpio_pin(GPIO_PORT_C,13,0);
//	  delay_ms(50);
//
// }

}


