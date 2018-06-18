#include "gpio_interface.h"


unsigned char ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};


void display_number(int number){
//your code here
}

 int main(void){
	//TODO Connect the pin of 7 segment display to port A as shown in the whiteboard.(a->0,b->1_

   enable_gpio_clock(GPIO_CLOCK_A);

   //Configuring pin 13 of PORT C as output
   configure_gpio_pin(GPIO_PORT_C,13,0x0001);


  //TODO CONFIGURE pin 0-8 of GPIO_port A as output.
  //hint: use 'for' loop with loop variable i=0 to 7 as pin number -->checkpoint one



   while (1)
   {
	   	  //Displaying number 1 using write_gpio_pin function for common anode configuration
	      write_gpio_pin(GPIO_PORT_A,0,1);
	 	  write_gpio_pin(GPIO_PORT_A,1,0);
	 	  write_gpio_pin(GPIO_PORT_A,2,0);
	 	  write_gpio_pin(GPIO_PORT_A,3,1);
	 	  write_gpio_pin(GPIO_PORT_A,4,1);
	 	  write_gpio_pin(GPIO_PORT_A,5,1);
	 	  write_gpio_pin(GPIO_PORT_A,6,1);
	 	  write_gpio_pin(GPIO_PORT_A,7,1);

	 	  //****************************************************************************************
	 	  //TODO display any number between 0-9 using write_gpio_pin(portname,pinnumber,value) as above;
	 	  //your code here
	 	  //***************************************************************************************

	 	  //*************************************************************************************
	 	  //TODO display the same number using "write_gpio_port(portname,value)
	 	  //hint write_gpio_port(GPIO_PORT_A,0xf9);
	 	  //*******************************************************************************

	 	  //************************************************************************************
	 	  //declare a GLOBAL character array containing the required hex value from 0 to 9
	 	  //************************************************************************************


	 	  //****************************************************************************************
	 	  //TODO Complete  the implementation for the function "void display_number(int number)" and call the function
	 	  //hint:display_number(1);
	 	  //*****************************************************************************************


	 	  /*
	 	   * int number =0;
	 	   * display_number(number);
	 	   * delay(500);
	 	   * number++;
	 	   */
	 	  //uncomment above code
	 	  //TODO Modify your code so that number switches from 9 to 0;
	 	  //hint:use if condition

  }
 }

