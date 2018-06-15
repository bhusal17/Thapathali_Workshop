
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"
#include "api_keypad_driver.h"


int main(void)
{
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
  enable_gpio_clock(GPIO_CLOCK_B);
  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);

  api_gpio_config_for_keypad();
  LCD_Init();
  uint8_t pressedKey;

  while(1){

	  lcd_string_write("Future Lab");
  }
}



