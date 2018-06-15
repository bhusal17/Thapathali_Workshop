#include "gpio_interface.h"

#define SEGA_PORT GPIO_PORT_A
#define SEGA_Pin 3
#define SEGB_PORT GPIO_PORT_A
#define SEGB_Pin 8
#define SEGC_PORT GPIO_PORT_A
#define SEGC_Pin 9
#define SEGD_PORT GPIO_PORT_B
#define SEGD_Pin 0
#define SEGE_PORT GPIO_PORT_B
#define SEGE_Pin 14
#define SEGF_PORT GPIO_PORT_B
#define SEGF_Pin 11
#define SEGG_PORT GPIO_PORT_C
#define SEGG_Pin 15
#define SEGDP_PORT GPIO_PORT_C
#define SEGDP_Pin 13

typedef struct{

	GPIORegister_structure *segX_port;
	uint8_t segX_pin;
}seven_segment_configStruct;


void api_gpio_config_for_7segment();
void api_7segment_out(uint8_t data_to_display);
