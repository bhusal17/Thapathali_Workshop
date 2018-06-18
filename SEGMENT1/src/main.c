
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"
#include "api_7segment_driver.h"

#define segport gpio_port_a


//uint8_t newch[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
void display_number(int );

void segmentPortInit(GPIORegister_structure *GPIOX){
segport->ConfigRegLow = 0x11111111;
}

void display_number(int number){
	write_gpio_port(GPIO_PORT_A,ch[number]);


}

void display_number(volatile uint32_t portbaseaddress,)

int main(void)
{

 // int number = 0;
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
  enable_gpio_clock(GPIO_CLOCK_B);


//  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,1,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,2,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,3,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,4,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,5,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,6,0x0001);
//  configure_gpio_pin(GPIO_PORT_A,7,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);
//  configure_gpio_port(GPIO_PORT_A,0x11111111,0x11111111);


  api_gpio_config_for_7segment();
  //api_7segment_out(0x7f);

//  while(1){
//
//  }

  while(1){
	  for(uint8_t i=0; i<9; i++){
		 api_7segment_out(ch[i]);
		 write_gpio_pin(GPIO_PORT_C,13,0);
		  delay_ms(500);
		  write_gpio_pin(GPIO_PORT_C,13,1);
		  delay_ms(500);
	  }
  }

}




//  while (1)
//  {

//	  display_number(number);
//	  delay_ms(500);
//	  number++;
//	  if(number>9){
//		  number=0;
//	  }

//
//
// }
//}

