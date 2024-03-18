#include "c8051F020.h"

CSEG
        ORG     0000h                   // starting at address 0 (jumps here upon reset)

        CLR     EA                      // disable all interrupts
        MOV     WDTCN, #0DEh            // disable software watchdog timer
        MOV     WDTCN, #0ADh

        MOV     A, P74OUT
        ORL     A, #008h                // 1: P5.[7:4] configured as Push-Pull.
        ANL     A, #0FBh                // 0: P5.[3:0] configured as Open-Drain.
        MOV     P74OUT, A

        ANL     P5, #00Fh               // Turn off LED (P5.4=P5.5=P5.6=P5.7=0)
        ORL     P5, #00Fh               // Enable internal pull-up for P5.0,5.1,5.2,5.3 (Button)

LOOP_FOREVER:
				ANL			P5, #00Fh		//reset LED

        MOV     A, P5                   // Read port 5 value

				XRL     A, #00Fh			// reverse button input because 0 means enable wihle enable LED is 1
				JZ			LOOP_FOREVER

				RR			A				//rotate right for 4 bits
				RR			A
				RR			A
				RR			A
		
				MOV			P5, A

				ORL     P5, #00Fh		//reset button
		
        JMP     LOOP_FOREVER

END