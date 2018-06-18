#ifndef __PORT_STRUCT__
#define __PORT_STRUCT__
//just for test
#include<stdint.h>
#include<main.h>

//GPIO CLOCK
#define GPIO_CLOCK_A 0
#define GPIO_CLOCK_B 1
#define GPIO_CLOCK_C 2

//Base address of GPIO PORT Register
#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000
#define GPIOD_BASE_ADDRESS 0x40011400
#define GPIOE_BASE_ADDRESS 0x40011800


//GPIO Register Structure 
typedef struct{
   volatile uint32_t ConfigRegLow;
   volatile uint32_t ConfigRegHigh;
   //TODO assign remaining register to this structure
}GPIORegister_structure;


//Macro definition of Base address of Register related to Ports

#define GPIO_PORT_A ( (GPIORegister_structure *) GPIOA_BASE_ADDRESS )
//TODO define "GPIO_PORT_B" and "GPIO_PORT_C" as above




#endif

