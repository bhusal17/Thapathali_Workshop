
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"




int main(void)
{
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);


  //Accessing directly using registers
    volatile uint32_t *GPIO_CRH = 0x0, *GPIO_ODR=0x0;
    GPIO_CRH = (uint32_t*)(0x40011000+0x04);
    GPIO_ODR = (uint32_t *)(0x40011000+0x0C);
    *GPIO_CRH = *GPIO_CRH | 0x00100000;


  //GPIO_PORT_C->OutputDatareg = 0x0000;
  while (1)
  {
//	  GPIO_PORT_C->OutputDatareg = 0xFFFF;
//	  delay_ms(50);
//	  GPIO_PORT_C->OutputDatareg = 0x0000;
//	  delay_ms(50);

	  *GPIO_ODR = 0x2000;
	  delay_ms(1000);
	  *GPIO_ODR = 0x0000;
	  delay_ms(1000);
 }

}


