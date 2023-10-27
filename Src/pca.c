/**
 * @file pca.c
 * @author Parth Kharade (you@domain.com)
 * @brief  APIs to access the PCA module.
 * @version 0.1
 * @date 2023-10-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "at89c51ed2.h"
#include "stdint.h"
#include "pca.h"
void init_pca(){
	P1 |= (1<<3)|(1<<4);


	CCAP0L = 171;
	CCAP0H = 171;

	CCAP1L = 0xFF;
	CCAP1H = 0x7F;

	CCAP4L = 0xFF;
	CCAP4H = 0xFF;

	CCAPM0 |= ECOM;
	CCAPM1 |= ECOM|MAT;
	
	CMOD |= CPS0;
	CR = 1;
}
void start_pwm(){
	CCAPM0 |= (PWM);
}
void stop_pwm(){
	CCAPM0 &= ~(PWM);
}
void start_tog(){
	CCAPM1 |= (TOG);
}
void stop_tog(){
	CCAPM1 &= ~(TOG);
}
void enable_dog(){
	uint16_t cc4_val = (CH<<8)|(CL);
	cc4_val-=100;
	CCAP4L = cc4_val&0xFF;
	CCAP4H = cc4_val>>8;
	CMOD |= WDTE;
}
void disable_dog(){
	CMOD &= ~WDTE;
}
