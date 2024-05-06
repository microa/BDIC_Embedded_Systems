/****************************************************
*	Describe:Read ADC Value 						              *
*	BDIC Embedded System							                *
*	Re.Binhua, Version:06,May.2024				          	*
****************************************************/
#include <c8051f020.h>

void init_System(){
	WDTCN = 0xDE;	//watchdog
	WDTCN = 0xAD;	//watchdog
}

void init_ADC(){
	REF0CN=0x03;
	AMX0SL=0x02;
	ADC0CN=0x80;
}

void main(){
	long val_adc = 0;

	init_System();	//initializing system
	init_ADC();		//initializing ADC

	AD0BUSY=1;
	while(!AD0INT);		//check busy
	val_adc = ADC0H*256+ADC0L;	//read ADC value once.

}
