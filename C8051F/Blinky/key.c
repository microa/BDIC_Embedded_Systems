/****************************************************
*	Describe:Read 1 Key		 					                	*
*	BDIC Embedded System					                		*
*	Re.Binhua, Version:07,May.2024			          		*
****************************************************/
#include <c8051f020.h>

void init_Clock(void){
	OSCICN = 0x86; 		//-- 1000 0110b
	while ( (OSCICN & 0x10) == 0);	//-- poll for IFRDY -> 1
}

void init_Port(void){
	P74OUT &= 0xFB;		// 0: P5.[3:0] configured as Open-Drain.
	P5 |= 0x0F;			// set 
}

void init_sys(){
	WDTCN = 0xDE;		// disable watchdog timer
	WDTCN = 0xAD;
	init_Clock();
	init_Port();
}

void main(void){	
	char key = 0;
	init_sys();
	key = P5 & 0x01;	//read 1 key: P5.0
}
