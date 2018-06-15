#include "api_7segment_driver.h"

seven_segment_configStruct segmentConfigMatrix[8]={
		 {SEGA_PORT, SEGA_Pin},
		 {SEGB_PORT, SEGB_Pin},
		 {SEGC_PORT, SEGC_Pin},
		 {SEGD_PORT, SEGD_Pin},
		 {SEGE_PORT, SEGE_Pin},
		 {SEGF_PORT, SEGF_Pin},
		 {SEGG_PORT, SEGG_Pin},
		 {SEGDP_PORT, SEGDP_Pin}
};


void api_gpio_config_for_7segment(){

	for(uint8_t i=0; i<8; i++){
		configure_gpio_pin(segmentConfigMatrix[i].segX_port,segmentConfigMatrix[i].segX_pin,1);
	}
}


void api_7segment_out(uint8_t data_to_display){

	for(uint8_t i=0; i<8; i++){
		write_gpio_pin(segmentConfigMatrix[i].segX_port, segmentConfigMatrix[i].segX_pin, (data_to_display>>i) & 0x01);
	}
}
