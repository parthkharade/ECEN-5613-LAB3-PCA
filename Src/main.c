#include "stdio.h"
#include "stdint.h"
#include "at89c51ed2.h"
#include "stdlib.h"
#include "serial.h"
#include "pca.h"
#include "core.h"
#define CODE_LOC 0x3000
volatile uint8_t interrupt = 0;
uint8_t reset_watchdog = 1;
void main(){
/************************HEADER START*******************************/
__code unsigned char __at (CODE_LOC) signature[4] = {0xA5,0xE5,0xE0,0xA5};                

__code unsigned char __at (CODE_LOC+4) id[4] = {35,255,0,0};

__code unsigned char __at (CODE_LOC+8) reserved1[4] = {0,0,0,0};

__code unsigned char __at (CODE_LOC+12) reserved2[4] = {0,0,0,0};

__code unsigned char __at (CODE_LOC+16) reserved3[4] = {0,0,0,0};

__code unsigned char __at (CODE_LOC+20) reserved4[4] = {0,0,0,0};

__code unsigned char __at (CODE_LOC+24) reserved5[4] = {0,0,0,0};

__code unsigned char __at (CODE_LOC+28) reserved6[4] = {255,255,255,255};

__code unsigned char __at (CODE_LOC+32) pname[] = "PCA";

__code unsigned char __at (0x2003) LJUMP[] = {0x02,0x30,0x43};
/************************HEADER END********************************/
	

	reset_watchdog = 1;
	init_clocks();
	init_INT0();
	init_uart();
	init_pca();
	enable_dog();
	printf_tiny("\r\n Enter H to see a list of all available commands.");
	EA = 1;
	while(1){
		if(reset_watchdog){
			reset_WDT();
		}
		printf_tiny("\r\n >> ");
		char comm = getchar();
		putchar(comm);
		if(reset_watchdog){
			reset_WDT();
		}		
		switch (comm)
		{
		case 'A':
			start_pwm();
			/* code */
			break;
		case 'B':
			stop_pwm();
			/* code */
			break;			
		case 'C':{
			init_uart_slow();
			CKRL = 0;
			break;
		}
		case 'D':{
			init_uart();
			CKRL = 255;
			break;
		}
		case 'E':
			PCON|=IDL;
			break;
		case 'F':
			PCON|=PD;
			/* code */
			break;
		case 'G':
			reset_watchdog = 1;
			enable_dog();
			/* code */
			break;
		case 'H':
			disable_dog();
			printf_tiny("\r\n -----------------------------------");
			printf_tiny("\r\n |            Help Menu            |");
			printf_tiny("\r\n |---------------------------------|");
			printf_tiny("\r\n |   A.  | Run PWM                 |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   B.  | Stop PWM                |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   C.  | Fclk Peripheral at MIN  |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   D.  | Fclk Peripheral at MAX  |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   E.  | Idle Mode               |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   F.  | Power Down Mode         |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   G.  | Enable Watchdog         |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   H.  | Help Menu               |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   I.  | Disable Watchdog        |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   J.  | Let Watchdog Overflow   |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   K.  | Start High-Speed TOG    |");
			printf_tiny("\r\n |-------|-------------------------|");
			printf_tiny("\r\n |   L.  | Stop High-Speed TOG     |");
			printf_tiny("\r\n -----------------------------------");
			enable_dog();
			break;	
		case 'I':
			disable_dog();
			/* code */
			break;			
		case 'J':
			reset_watchdog = 0;
			/* code */
			break;
		case 'K':
			start_tog();
			/* code */
			break;
		case 'L':
			stop_tog();
			/* code */
			break;													
		default:
			break;
		}
	}
}
void int0_isr () __interrupt(0){
}
