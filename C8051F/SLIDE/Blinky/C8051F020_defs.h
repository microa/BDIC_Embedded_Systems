//-----------------------------------------------------------------------------
// C8051F020_defs.h
//-----------------------------------------------------------------------------
// Copyright 2007, Silicon Laboratories, Inc.
// http://www.silabs.com
//
// Program Description:
//
// Register/bit definitions for the C8051F02x family.
// **Important Note**: The si_toolchain.h header file should be included
// before including this header file.
//
// Target:         C8051F020, 'F021, 'F022, 'F023
// Tool chain:     Generic
// Command Line:   None
//
// Release 1.4 - 20 AUG 2012 (TP)
//    -Added #define for _XPAGE to provide support for SDCC memory paging
//     (pdata)
// Release 1.3 - 07 AUG 2007 (PKC)
//    -Removed #include "si_toolchain.h". The C source file should include it.
// Release 1.2 - 09 JUL 2007 (PKC)
//    -Reformatted header file to enable portable SFR definitions

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F020_DEFS_H
#define C8051F020_DEFS_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

SI_SFR(P0, 0x80);                        // Port 0 Latch
SI_SFR(SP, 0x81);                        // Stack Pointer
SI_SFR(DPL, 0x82);                       // Data Pointer Low
SI_SFR(DPH, 0x83);                       // Data Pointer High
SI_SFR(P4, 0x84);                        // Port 4 Latch
SI_SFR(P5, 0x85);                        // Port 5 Latch
SI_SFR(P6, 0x86);                        // Port 6 Latch
SI_SFR(PCON, 0x87);                      // Power Control
SI_SFR(TCON, 0x88);                      // Timer/Counter Control
SI_SFR(TMOD, 0x89);                      // Timer/Counter Mode
SI_SFR(TL0, 0x8A);                       // Timer/Counter 0 Low
SI_SFR(TL1, 0x8B);                       // Timer/Counter 1 Low
SI_SFR(TH0, 0x8C);                       // Timer/Counter 0 High
SI_SFR(TH1, 0x8D);                       // Timer/Counter 1 High
SI_SFR(CKCON, 0x8E);                     // Clock Control
SI_SFR(PSCTL, 0x8F);                     // Program Store R/W Control
SI_SFR(P1, 0x90);                        // Port 1 Latch
SI_SFR(TMR3CN, 0x91);                    // Timer/Counter 3 Control
SI_SFR(TMR3RLL, 0x92);                   // Timer/Counter 3 Reload Low
SI_SFR(TMR3RLH, 0x93);                   // Timer/Counter 3 Reload High
SI_SFR(TMR3L, 0x94);                     // Timer/Counter 3 Low
SI_SFR(TMR3H, 0x95);                     // Timer/Counter 3 High
SI_SFR(P7, 0x96);                        // Port 7 Latch
SI_SFR(SCON0, 0x98);                     // Serial Port UART0 Control
SI_SFR(SBUF0, 0x99);                     // Serial Port UART0 Data Buffer
SI_SFR(SPI0CFG, 0x9A);                   // SPI0 Configuration
SI_SFR(SPI0DAT, 0x9B);                   // SPI0 Data
SI_SFR(ADC1, 0x9C);                      // ADC1 Data
SI_SFR(SPI0CKR, 0x9D);                   // SPI0 Clock Rate Control
SI_SFR(CPT0CN, 0x9E);                    // Comparator 0 Control
SI_SFR(CPT1CN, 0x9F);                    // Comparator 1 Control
SI_SFR(P2, 0xA0);                        // Port 2 Latch
SI_SFR(EMI0TC, 0xA1);                    // EMIF Timing Control
SI_SFR(EMI0CF, 0xA3);                    // EMIF Configuration
SI_SFR(P0MDOUT, 0xA4);                   // Port 0 Output Mode Configuration
SI_SFR(P1MDOUT, 0xA5);                   // Port 1 Output Mode Configuration
SI_SFR(P2MDOUT, 0xA6);                   // Port 2 Output Mode Configuration
SI_SFR(P3MDOUT, 0xA7);                   // Port 3 Output Mode Configuration
SI_SFR(IE, 0xA8);                        // Interrupt Enable
SI_SFR(SADDR0, 0xA9);                    // Serial Port UART0 Slave Address
SI_SFR(ADC1CN, 0xAA);                    // ADC1 Control
SI_SFR(ADC1CF, 0xAB);                    // ADC1 Analog Mux Configuration
SI_SFR(AMX1SL, 0xAC);                    // ADC1 Analog Mux Channel Select
SI_SFR(P3IF, 0xAD);                      // Port 3 External Interrupt Flags
SI_SFR(SADEN1, 0xAE);                    // Serial Port UART1 Slave Address Mask
SI_SFR(EMI0CN, 0xAF);                    // EMIF Control
SI_SFR(P3, 0xB0);                        // Port 3 Latch
SI_SFR(OSCXCN, 0xB1);                    // External Oscillator Control
SI_SFR(OSCICN, 0xB2);                    // Internal Oscillator Control
SI_SFR(P74OUT, 0xB5);                    // Ports 4 - 7 Output Mode
SI_SFR(FLSCL, 0xB6);                     // Flash Memory Timing Prescaler
SI_SFR(FLACL, 0xB7);                     // Flash Acess Limit
SI_SFR(IP, 0xB8);                        // Interrupt Priority
SI_SFR(SADEN0, 0xB9);                    // Serial Port UART0 Slave Address Mask
SI_SFR(AMX0CF, 0xBA);                    // ADC0 Mux Configuration
SI_SFR(AMX0SL, 0xBB);                    // ADC0 Mux Channel Selection
SI_SFR(ADC0CF, 0xBC);                    // ADC0 Configuration
SI_SFR(P1MDIN, 0xBD);                    // Port 1 Input Mode
SI_SFR(ADC0L, 0xBE);                     // ADC0 Data Low
SI_SFR(ADC0H, 0xBF);                     // ADC0 Data High
SI_SFR(SMB0CN, 0xC0);                    // SMBus0 Control
SI_SFR(SMB0STA, 0xC1);                   // SMBus0 Status
SI_SFR(SMB0DAT, 0xC2);                   // SMBus0 Data
SI_SFR(SMB0ADR, 0xC3);                   // SMBus0 Slave Address
SI_SFR(ADC0GTL, 0xC4);                   // ADC0 Greater-Than Register Low
SI_SFR(ADC0GTH, 0xC5);                   // ADC0 Greater-Than Register High
SI_SFR(ADC0LTL, 0xC6);                   // ADC0 Less-Than Register Low
SI_SFR(ADC0LTH, 0xC7);                   // ADC0 Less-Than Register High
SI_SFR(T2CON, 0xC8);                     // Timer/Counter 2 Control
SI_SFR(T4CON, 0xC9);                     // Timer/Counter 4 Control
SI_SFR(RCAP2L, 0xCA);                    // Timer/Counter 2 Capture Low
SI_SFR(RCAP2H, 0xCB);                    // Timer/Counter 2 Capture High
SI_SFR(TL2, 0xCC);                       // Timer/Counter 2 Low
SI_SFR(TH2, 0xCD);                       // Timer/Counter 2 High
SI_SFR(SMB0CR, 0xCF);                    // SMBus0 Clock Rate
SI_SFR(PSW, 0xD0);                       // Program Status Word
SI_SFR(REF0CN, 0xD1);                    // Voltage Reference 0 Control
SI_SFR(DAC0L, 0xD2);                     // DAC0 Register Low
SI_SFR(DAC0H, 0xD3);                     // DAC0 Register High
SI_SFR(DAC0CN, 0xD4);                    // DAC0 Control
SI_SFR(DAC1L, 0xD5);                     // DAC1 Register Low
SI_SFR(DAC1H, 0xD6);                     // DAC1 Register High
SI_SFR(DAC1CN, 0xD7);                    // DAC1 Control
SI_SFR(PCA0CN, 0xD8);                    // PCA0 Control
SI_SFR(PCA0MD, 0xD9);                    // PCA0 Mode
SI_SFR(PCA0CPM0, 0xDA);                  // PCA0 Module 0 Mode Register
SI_SFR(PCA0CPM1, 0xDB);                  // PCA0 Module 1 Mode Register
SI_SFR(PCA0CPM2, 0xDC);                  // PCA0 Module 2 Mode Register
SI_SFR(PCA0CPM3, 0xDD);                  // PCA0 Module 3 Mode Register
SI_SFR(PCA0CPM4, 0xDE);                  // PCA0 Module 4 Mode Register
SI_SFR(ACC, 0xE0);                       // Accumulator
SI_SFR(XBR0, 0xE1);                      // Port I/O Crossbar Control 0
SI_SFR(XBR1, 0xE2);                      // Port I/O Crossbar Control 1
SI_SFR(XBR2, 0xE3);                      // Port I/O Crossbar Control 2
SI_SFR(RCAP4L, 0xE4);                    // Timer 4 Capture Register Low
SI_SFR(RCAP4H, 0xE5);                    // Timer 4 Capture Register High
SI_SFR(EIE1, 0xE6);                      // External Interrupt Enable 1
SI_SFR(EIE2, 0xE7);                      // External Interrupt Enable 2
SI_SFR(ADC0CN, 0xE8);                    // ADC0 Control
SI_SFR(PCA0L, 0xE9);                     // PCA0 Counter Low
SI_SFR(PCA0CPL0, 0xEA);                  // PCA0 Capture 0 Low
SI_SFR(PCA0CPL1, 0xEB);                  // PCA0 Capture 1 Low
SI_SFR(PCA0CPL2, 0xEC);                  // PCA0 Capture 2 Low
SI_SFR(PCA0CPL3, 0xED);                  // PCA0 Capture 3 Low
SI_SFR(PCA0CPL4, 0xEE);                  // PCA0 Capture 4 Low
SI_SFR(RSTSRC, 0xEF);                    // Reset Source Configuration/Status
SI_SFR(B, 0xF0);                         // B Register
SI_SFR(SCON1, 0xF1);                     // Serial Port UART1 Control
SI_SFR(SBUF1, 0xF2);                     // Serail Port UART1 Data
SI_SFR(SADDR1, 0xF3);                    // Serail Port UART1 Slave Address
SI_SFR(TL4, 0xF4);                       // Timer/Counter 4 Low
SI_SFR(TH4, 0xF5);                       // Timer/Counter 4 High
SI_SFR(EIP1, 0xF6);                      // External Interrupt Priority 1
SI_SFR(EIP2, 0xF7);                      // External Interrupt Priority 2
SI_SFR(SPI0CN, 0xF8);                    // SPI0 Control
SI_SFR(PCA0H, 0xF9);                     // PCA0 Counter High
SI_SFR(PCA0CPH0, 0xFA);                  // PCA0 Capture 0 High
SI_SFR(PCA0CPH1, 0xFB);                  // PCA0 Capture 1 High
SI_SFR(PCA0CPH2, 0xFC);                  // PCA0 Capture 2 High
SI_SFR(PCA0CPH3, 0xFD);                  // PCA0 Capture 3 High
SI_SFR(PCA0CPH4, 0xFE);                  // PCA0 Capture 4 High
SI_SFR(WDTCN, 0xFF);                     // Watchdog Timer Control

//-----------------------------------------------------------------------------
// 16-bit Register Definitions (might not be supported by all compilers)
//-----------------------------------------------------------------------------

SI_SFR16(DP, 0x82);                      // Data Pointer
SI_SFR16(TMR3RL, 0x92);                  // Timer3 Reload Value
SI_SFR16(TMR3, 0x94);                    // Timer3 Counter
SI_SFR16(ADC0, 0xBE);                    // ADC0 Data
SI_SFR16(ADC0GT, 0xC4);                  // ADC0 Greater Than Window
SI_SFR16(ADC0LT, 0xC6);                  // ADC0 Less Than Window
SI_SFR16(RCAP2, 0xCA);                   // Timer2 Capture/Reload
SI_SFR16(T2, 0xCC);                      // Timer2 Counter
SI_SFR16(TMR2RL, 0xCA);                  // Timer2 Capture/Reload
SI_SFR16(TMR2, 0xCC);                    // Timer2 Counter
SI_SFR16(RCAP4, 0xE4);                   // Timer4 Capture/Reload
SI_SFR16(T4, 0xF4);                      // Timer4 Counter
SI_SFR16(TMR4RL, 0xE4);                  // Timer4 Capture/Reload
SI_SFR16(TMR4, 0xF4);                    // Timer4 Counter
SI_SFR16(DAC0, 0xD2);                    // DAC0 Data
SI_SFR16(DAC1, 0xD5);                    // DAC1 Data

//-----------------------------------------------------------------------------
// Address Definitions for bit-addressable SFRs
//-----------------------------------------------------------------------------

#define SFR_P0       0x80
#define SFR_TCON     0x88
#define SFR_P1       0x90
#define SFR_SCON0    0x98
#define SFR_P2       0xA0
#define SFR_IE       0xA8
#define SFR_P3       0xB0
#define SFR_IP       0xB8
#define SFR_SMB0CN   0xC0
#define SFR_T2CON    0xC8
#define SFR_PSW      0xD0
#define SFR_PCA0CN   0xD8
#define SFR_ACC      0xE0
#define SFR_ADC0CN   0xE8
#define SFR_B        0xF0
#define SFR_SPI0CN   0xF8

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

// TCON 0x88
SI_SBIT(TF1, SFR_TCON, 7);               // Timer 1 Overflow Flag
SI_SBIT(TR1, SFR_TCON, 6);               // Timer 1 On/Off Control
SI_SBIT(TF0, SFR_TCON, 5);               // Timer 0 Overflow Flag
SI_SBIT(TR0, SFR_TCON, 4);               // Timer 0 On/Off Control
SI_SBIT(IE1, SFR_TCON, 3);               // Ext. Interrupt 1 Edge Flag
SI_SBIT(IT1, SFR_TCON, 2);               // Ext. Interrupt 1 Type
SI_SBIT(IE0, SFR_TCON, 1);               // Ext. Interrupt 0 Edge Flag
SI_SBIT(IT0, SFR_TCON, 0);               // Ext. Interrupt 0 Type

// SCON0 0x98
SI_SBIT(SM00, SFR_SCON0, 7);             // Serial Mode Control Bit 0
SI_SBIT(SM10, SFR_SCON0, 6);             // Serial Mode Control Bit 1
SI_SBIT(SM20, SFR_SCON0, 5);             // Multiprocessor Communication Enable
SI_SBIT(REN0, SFR_SCON0, 4);             // Receive Enable
SI_SBIT(TB80, SFR_SCON0, 3);             // Transmit Bit 8
SI_SBIT(RB80, SFR_SCON0, 2);             // Receive Bit 8
SI_SBIT(TI0, SFR_SCON0, 1);              // Transmit Interrupt Flag
SI_SBIT(RI0, SFR_SCON0, 0);              // Receive Interrupt Flag

// IE 0xA8
SI_SBIT(EA, SFR_IE, 7);                  // Global Interrupt Enable
SI_SBIT(IEGF0, SFR_IE, 6);               // General Purpose Flag 0
SI_SBIT(ET2, SFR_IE, 5);                 // Timer 2 Interrupt Enable
SI_SBIT(ES0, SFR_IE, 4);                 // Uart0 Interrupt Enable
SI_SBIT(ET1, SFR_IE, 3);                 // Timer 1 Interrupt Enable
SI_SBIT(EX1, SFR_IE, 2);                 // External Interrupt 1 Enable
SI_SBIT(ET0, SFR_IE, 1);                 // Timer 0 Interrupt Enable
SI_SBIT(EX0, SFR_IE, 0);                 // External Interrupt 0 Enable

// IP 0xB8
                                       // Bit7 UNUSED
                                       // Bit6 UNUSED
SI_SBIT(PT2, SFR_IP, 5);                 // Timer 2 Priority
SI_SBIT(PS, SFR_IP, 4);                  // Serial Port Priority
SI_SBIT(PT1, SFR_IP, 3);                 // Timer 1 Priority
SI_SBIT(PX1, SFR_IP, 2);                 // External Interrupt 1 Priority
SI_SBIT(PT0, SFR_IP, 1);                 // Timer 0 Priority
SI_SBIT(PX0, SFR_IP, 0);                 // External Interrupt 0 Priority

// SMB0CN 0xC0
SI_SBIT(BUSY, SFR_SMB0CN, 7);            // SMBus 0 Busy
SI_SBIT(ENSMB, SFR_SMB0CN, 6);           // SMBus 0 Enable
SI_SBIT(STA, SFR_SMB0CN, 5);             // SMBus 0 Start Flag
SI_SBIT(STO, SFR_SMB0CN, 4);             // SMBus 0 Stop Flag
SI_SBIT(SI, SFR_SMB0CN, 3);              // SMBus 0 Interrupt Pending Flag
SI_SBIT(AA, SFR_SMB0CN, 2);              // SMBus 0 Assert/Acknowledge Flag
SI_SBIT(SMBFTE, SFR_SMB0CN, 1);          // SMBus 0 Free Timer Enable
SI_SBIT(SMBTOE, SFR_SMB0CN, 0);          // SMBus 0 Timeout Enable

// T2CON 0xC8
SI_SBIT(TF2, SFR_T2CON, 7);              // Timer 2 Overflow Flag
SI_SBIT(EXF2, SFR_T2CON, 6);             // External Flag
SI_SBIT(RCLK0, SFR_T2CON, 5);            // Uart0 Rx Clock Source
SI_SBIT(TCLK0, SFR_T2CON, 4);            // Uart0 Tx Clock Source
SI_SBIT(EXEN2, SFR_T2CON, 3);            // Timer 2 External Enable Flag
SI_SBIT(TR2, SFR_T2CON, 2);              // Timer 2 On/Off Control
SI_SBIT(CT2, SFR_T2CON, 1);              // Timer Or Counter Select
SI_SBIT(CPRL2, SFR_T2CON, 0);            // Capture Or Reload Select

//  PSW 0xD0
SI_SBIT(CY, SFR_PSW, 7);                 // Carry Flag
SI_SBIT(AC, SFR_PSW, 6);                 // Auxiliary Carry Flag
SI_SBIT(F0, SFR_PSW, 5);                 // User Flag 0
SI_SBIT(RS1, SFR_PSW, 4);                // Register Bank Select 1
SI_SBIT(RS0, SFR_PSW, 3);                // Register Bank Select 0
SI_SBIT(OV, SFR_PSW, 2);                 // Overflow Flag
SI_SBIT(F1, SFR_PSW, 1);                 // User Flag 1
SI_SBIT(P, SFR_PSW, 0);                  // Accumulator Parity Flag

// PCA0CN 0xD8
SI_SBIT(CF, SFR_PCA0CN, 7);              // PCA 0 Counter Overflow Flag
SI_SBIT(CR, SFR_PCA0CN, 6);              // PCA 0 Counter Run Control Bit
                                       // Bit5 UNUSED
SI_SBIT(CCF4, SFR_PCA0CN, 4);            // PCA 0 Module 4 Interrupt Flag
SI_SBIT(CCF3, SFR_PCA0CN, 3);            // PCA 0 Module 3 Interrupt Flag
SI_SBIT(CCF2, SFR_PCA0CN, 2);            // PCA 0 Module 2 Interrupt Flag
SI_SBIT(CCF1, SFR_PCA0CN, 1);            // PCA 0 Module 1 Interrupt Flag
SI_SBIT(CCF0, SFR_PCA0CN, 0);            // PCA 0 Module 0 Interrupt Flag

// ADC0CN 0xE8
SI_SBIT(AD0EN, SFR_ADC0CN, 7);           // ADC 0 Enable
SI_SBIT(AD0TM, SFR_ADC0CN, 6);           // ADC 0 Track Mode
SI_SBIT(AD0INT, SFR_ADC0CN, 5);          // ADC 0 Converision Complete Interrupt Flag
SI_SBIT(AD0BUSY, SFR_ADC0CN, 4);         // ADC 0 Busy Flag
SI_SBIT(AD0CM1, SFR_ADC0CN, 3);          // ADC 0 Start Of Conversion Mode Bit 1
SI_SBIT(AD0CM0, SFR_ADC0CN, 2);          // ADC 0 Start Of Conversion Mode Bit 0
SI_SBIT(AD0WINT, SFR_ADC0CN, 1);         // ADC 0 Window Compare Interrupt Flag
SI_SBIT(AD0LJST, SFR_ADC0CN, 0);         // ADC 0 Right Justify Data Bit

// SPI0CN 0xF8
SI_SBIT(SPIF, SFR_SPI0CN, 7);            // SPI 0 Interrupt Flag
SI_SBIT(WCOL, SFR_SPI0CN, 6);            // SPI 0 Write Collision Flag
SI_SBIT(MODF, SFR_SPI0CN, 5);            // SPI 0 Mode Fault Flag
SI_SBIT(RXOVRN, SFR_SPI0CN, 4);          // SPI 0 Rx Overrun Flag
SI_SBIT(TXBSY, SFR_SPI0CN, 3);           // SPI 0 Tx Busy Flag
SI_SBIT(SLVSEL, SFR_SPI0CN, 2);          // SPI 0 Slave Select
SI_SBIT(MSTEN, SFR_SPI0CN, 1);           // SPI 0 Master Enable
SI_SBIT(SPIEN, SFR_SPI0CN, 0);           // SPI 0 SPI Enable

//-----------------------------------------------------------------------------
// Interrupt Priorities
//-----------------------------------------------------------------------------

#define INTERRUPT_INT0           0     // External Interrupt 0
#define INTERRUPT_TIMER0         1     // Timer0 Overflow
#define INTERRUPT_INT1           2     // External Interrupt 1
#define INTERRUPT_TIMER1         3     // Timer1 Overflow
#define INTERRUPT_UART0          4     // Serial Port UART0
#define INTERRUPT_TIMER2         5     // Timer2 Overflow
#define INTERRUPT_SPI0           6     // SPI0 Interface
#define INTERRUPT_SMBUS0         7     // SMBus0 Interface
#define INTERRUPT_ADC0_WINDOW    8     // ADC0 Window Comparison
#define INTERRUPT_PCA0           9     // PCA0 Peripheral
#define INTERRUPT_COMPARATOR0F   10    // Comparator0 Falling Edge
#define INTERRUPT_COMPARATOR0R   11    // Comparator0 Rising Edge
#define INTERRUPT_COMPARATOR1F   12    // Comparator1 Falling Edge
#define INTERRUPT_COMPARATOR1R   13    // Comparator1 Rising Edge
#define INTERRUPT_TIMER3         14    // Timer3 Overflow
#define INTERRUPT_ADC0_EOC       15    // ADC0 End Of Conversion
#define INTERRUPT_TIMER4         16    // Timer4 Overflow
#define INTERRUPT_ADC1_EOC       17    // ADC1 End Of Conversion
#define INTERRUPT_INT6           18    // External Interrupt 6
#define INTERRUPT_INT7           19    // External Interrupt 7
#define INTERRUPT_UART1          20    // Serial Port UART1
#define INTERRUPT_XTAL_READY     21    // External Crystal Oscillator Ready

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SI_SFR(_XPAGE, 0xAF); // Point to the EMI0CN register

#endif

//-----------------------------------------------------------------------------
// Header File PreProcessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F020_DEFS_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
