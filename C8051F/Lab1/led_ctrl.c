#include <c8051f020.h>

void init_Clock(void){
	OSCICN = 0x86; 		//-- 1000 0110b
	while ( (OSCICN & 0x10) == 0);	//-- poll for IFRDY -> 1
}

void init_Port(void){
	P74OUT |= 0x08;		// 1: P5.[7:4] configured as Push-Pull.
	P74OUT &= 0xFB;		// 0: P5.[3:0] configured as Open-Drain.
	P5 = 0x0F;
}

void init_sys(){
	WDTCN = 0xDE;		// disable watchdog timer
	WDTCN = 0xAD;
	init_Clock();
	init_Port();
}

void delay(long s){
	while(s--);
}

void main(void)
{	
	init_sys();
    while(1)
    {
		P5 |= 0x80;	//turn on P5.7
		delay(100000);
		P5 |= 0x40;	//turn on P5.6
		delay(100000);
		P5 |= 0x20;	//turn on P5.5
		delay(100000);
		P5 |= 0x10;	//turn on P5.5
		delay(100000);
		P5 &= 0x0F;	//turn off all LEDs
		delay(100000);
		P5 |= 0xF0; //turn on all LEDs
		delay(100000);
		P5 &= 0x0F;	//turn off all LEDs
		delay(100000);
	}
}
