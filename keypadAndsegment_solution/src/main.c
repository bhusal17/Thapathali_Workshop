
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"
#include "api_keypad_driver.h"
#include "api_7segment_driver.h"
uint8_t ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int main(void)
{
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
  enable_gpio_clock(GPIO_CLOCK_B);
  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);

  api_gpio_config_for_keypad();
  api_gpio_config_for_7segment();
  uint8_t pressedKey;

  while(1){

	  pressedKey= api_scan_keypad();
	  api_7segment_out(ch[pressedKey]);
//	  delay_ms(1000);

//	  if(pressedKey%2 == 0 ){
//			  write_gpio_pin(GPIO_PORT_C,13,0);
//		  }
//		  else{
//			  write_gpio_pin(GPIO_PORT_C,13,1);
//		  }
//		  delay_ms(1000);

	  }
  }




