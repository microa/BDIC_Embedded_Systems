//Function: Blinky on-board LED to test your Toolstick and Daughter Card is undamaged and connected correctly. 
//Derived from http://www.kjit.bme.hu/images/Tantargyak/MSc_targyak/Jelfeldolgozas_a_kozlekedesben/ch7_toolstick_university_daughter_card.pdf
//

#include <c8051f020.h>
#include <stdio.h>
#include <intrins.h>

#define LED_PORT 0xF0   // LED端口地址掩码 (P5.7-P5.4)

void small_delay(char count){
	while(count--);
}

void big_delay(char count){
	while(count--) small_delay(255);
}

void huge_delay(char count){
	while(count--) big_delay(255);
}

void init_Clock(void){
	//-- program the INTERNAL Oscillator Control Register
	OSCICN = 0x86; //-- 1000 0110b
	//-- Bit 7 : Missing Clock Detector Enabled (MSCLKE = 1)
	//-- Bit 3 : Uses Internal Osc as System Clock CLKSL = 0)
	//-- Bit 2 : Internal Osc. enabled (IOSCEN = 1)
	//-- Bit 1-0 : 8 MHz (IFCN1-IFCN0 set to 10)
	// OSCICN = 0x84; //-- 2 MHz
	// OSCICN = 0x85; //-- 4 MHz
	// OSCICN = 0x87; //-- 16 MHz
	while ( (OSCICN & 0x10) == 0);//-- poll for IFRDY -> 1
}

void init_Port(void){
	
	P74OUT = 0x08; // Output configuration for P4-7


	P5 |= 0x0F;    // 设置P5.7-P5.4为推挽输出,默认高电平
	P5 = P5 & 0xFF;
}

void main(void)
{
    unsigned char i;

	//-- disable watchdog timer
	WDTCN = 0xDE;
	WDTCN = 0xAD;


	
	init_Clock();
	init_Port();


    
    while(1)
    {
        for(i=0;i<4;i++)
        {
            P5 = 0x55;  // 点亮一个LED,其余熄灭
            huge_delay(20);
            P5 = 0x00;    // 全部熄灭
            huge_delay(20);
        }
    }
}


///if you want to initialize the ADC and Timer, use flowing code
/*
//--------------------------------------------------------------
void Init_ADC1(void)
{
REF0CN = 0x03; //-- Enable internal bias generator and
// internal reference buffer
// Select ADC1 reference from VREF1 pin
ADC1CF = 0x81; //-- SAR1 conversion clock=941KHz
// approx., Gain=1
AMX1SL = 0x00; //-- Select AIN1.0 input
ADC1CN = 0x82; //-- enable ADC1, Continuous Tracking
// Mode, Conversion initiated on Timer
// 3 overflow
}
//--------------------------------------------------------------
//--------------------------------------------------------------
// Interrupt Service Routine
void Timer3_ISR (void) interrupt 14
{
TMR3CN &= ~(0x80); //-- clear TF3 flag
//-- wait for ADC1 conversion to be over
while ( (ADC1CN & 0x20) == 0); //-- poll for AD1INT-->1
ADC1_reading = ADC1; //-- read ADC1 data
ADC1CN &= 0xDF; //-- clear AD1INT
}
//--------------------------------------------------------------
*/
