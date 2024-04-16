/****************************************************
*	Title:SPI-7Seg display			*
*	Port: 	P0.2:	SCK			*
*		P0.3:	SDO			*
*		P0.4:	SDI			*
*		P0.7:	SS			*
*	BDIC Embedded System			*
*	Re.Binhua, Version:16,Apr.2024		*
****************************************************/
#include <c8051f020.h>

sbit SS=P0^7;

void Delay(int i){
	while(i--);
}

void SPI_Send(int val_dat){
	SS = 0;
	SPI0DAT = val_dat;
	while(TXBSY);
	SS = 1;
	Delay(10);
}

void Print(int val_disp_num){
	SPI_Send(0x77);		//dicimal command
	SPI_Send(0x01);		//dicimal data: 0~63

	SPI_Send(0x79);		//cursor command
	SPI_Send(0);		//cursor position: 0~3

	SPI_Send(val_disp_num/1000%10);
	SPI_Send(val_disp_num/100%10);
	SPI_Send(val_disp_num/10%10);
	SPI_Send(val_disp_num%10);

}

void init_System(){
	WDTCN = 0xDE;	//watchdog
	WDTCN = 0xAD;	//watchdog
}

void init_IO(){
	P0MDOUT = 0xFF;
	
	XBR0 = 0x06;	//crossbar for SPI
	XBR2 = 0x40;	//crossbar enable

	SPI0CFG = 0x07;
	SPI0CN = 0x07;
	SPI0CKR = 0x09;	//SPI_clk == sys_clk/((0x09+1)*2)
	SS = 1;

	SPI_Send(0x7A);	//brightness control command
	SPI_Send(150);	//brightness control data: 0~255
	SPI_Send(0x76);	//clear display
}


void main(){
	init_System();	//initializing system
	init_IO();		//initializing io port
	
	while(1){
		Print(1234);	
		Delay(100);
	}
}




