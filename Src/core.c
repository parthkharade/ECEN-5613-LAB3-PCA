#include "core.h"
void init_uart(){
	PCON &= ~(SMOD1);
	BDRCON &= ~(SPD);
	BRL = 255;
	BDRCON|=(RBCK)|(TBCK)|(BRR);
}
void init_uart_slow(){
	PCON |= (SMOD1);
	BDRCON |= (SPD);
	BRL = 255;
	BDRCON|=(RBCK)|(TBCK)|(BRR);
}
void init_clocks(){
	CKCON0 |= X2;
	CKRL = 0xFF;
}
void init_INT0(){
	P3 |= (1<<2);
	IT0 = 1;
	EX0 = 1;
}
void reset_WDT(){
	uint16_t cc4_val = (CH<<8)|(CL);
	cc4_val-=100;
	CCAP4L = cc4_val&0xFF;
	CCAP4H = cc4_val>>8;
}