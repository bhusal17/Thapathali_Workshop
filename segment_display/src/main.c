
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"


unsigned char ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void display_number(int );

void display_number(int number){
	write_gpio_port(GPIO_PORT_A,ch[number]);
}

int main(void)
{

  int number = 0;
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
//  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,1,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,2,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,3,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,4,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,5,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,6,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,7,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);
  configure_gpio_port(GPIO_PORT_A,0x11111111,0x11111111);

  while (1)
  {
//	  write_gpio_pin(GPIO_PORT_A,0,0);
//	  write_gpio_pin(GPIO_PORT_A,1,0);
//	  write_gpio_pin(GPIO_PORT_A,2,0);
//	  write_gpio_pin(GPIO_PORT_A,3,0);
//	  write_gpio_pin(GPIO_PORT_A,4,0);
//	  write_gpio_pin(GPIO_PORT_A,5,0);
//	  write_gpio_pin(GPIO_PORT_A,6,0);
//	  write_gpio_pin(GPIO_PORT_A,7,0);
	  display_number(number);
	  delay_ms(500);
	  number++;
	  if(number>9){
		  number=0;
	  }
//	  write_gpio_pin(GPIO_PORT_C,13,0);
//	  write_gpio_pin(GPIO_PORT_A,0,1);
//	  write_gpio_pin(GPIO_PORT_A,1,1);
//	  write_gpio_pin(GPIO_PORT_A,2,1);
//	  write_gpio_pin(GPIO_PORT_A,3,1);
//	  write_gpio_pin(GPIO_PORT_A,4,1);
//	  write_gpio_pin(GPIO_PORT_A,5,1);
//	  write_gpio_pin(GPIO_PORT_A,6,1);
//	  write_gpio_pin(GPIO_PORT_A,7,1);


 }
}

