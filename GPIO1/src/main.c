#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"

//Base address macro definition of GPIO PORT A Register
#define GPIOA_BASE_ADDRESS 0x40010800
//TODO define base address for other remaining two ports B and C


int main(void)
{

  HAL_Init();
  enable_gpio_clock(GPIO_CLOCK_A);
  //TODO enable clock for port C


    volatile uint32_t *GPIOA_ConfigRegHigh = 0x0, *GPIOA_ODR=0x0;
    //TODO declare a pointer variable for "ConfigRegHigh" and
    //"OutputDataRegister" for port C -->checkpoint1


    GPIOA_ConfigRegHigh  = (uint32_t*)(0x40010800+0x04);
    //TODO substitute address 0x40010800 with its macro definition

    /* TODO Assign address to the pointer of "ConfigRegHigh"
    * and "OutputDataRegister of port C -->checkpoint 2
    *
    */

    //Configuring pin 10 of port A as an output
    *GPIOA_ConfigRegHigh = *GPIOA_ConfigRegHigh | 0x0000100;


    //TODO Configure pin 13 of port C as an output


  while (1)
  {
	  //TODO SENT HIGH TO THE pin 13 via OutputData register using pointer
	  //Hint:*GPIO_ODR = ox<value>;
	  delay_ms(50);
	  //TODO sENT low to the same pin
	  delay_ms(50);
 }

}
