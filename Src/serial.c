#include "stdio.h"
#include "at89c51ed2.h"
#include "serial.h"
#include "stdint.h"
uint16_t total_char ;
extern uint8_t reset_watchdog;
uint16_t cc4_val = 0;
int putchar (int c)
{
    while (!TI);
    SBUF = c;           // load serial port with transmit value
    TI = 0;             // clear TI flag

    return c;
}

int getchar (void)
{
    while (!RI){
		if(reset_watchdog){
			cc4_val = (CH<<8)|(CL);
			cc4_val-=100;
			CCAP4L = cc4_val&0xFF;
			CCAP4H = cc4_val>>8;
		}
	}
    RI = 0;                         // clear RI flag
	if(SBUF != 13) 
		total_char++;
    return SBUF;                    // return character from SBUF
}

int putstr (char *s)
{
    int i = 0;
    while (*s){            	// output characters until NULL found
        putchar(*s++);
        i++;
	}
}
uint8_t scan_num(uint16_t *num){
	char num_str[6];
	*num=0;
	uint8_t num_char = scanf(num_str,6);
	if(num_char){
		for(uint8_t i = 0 ;i<num_char;i++){
			if(*(num_str +i) >57 || *(num_str + i) <48){
				num_char = 0;
				break;
			}
			*(num)*=10;
			*num+=(*(num_str+i) - 48);
		}
	}
	return num_char;
}
uint8_t scanf(char *strbuf,uint8_t length){
	uint8_t index = 0;
	char buf_char;
	while(index<(length-1)){
		buf_char = getchar();
		if(buf_char == 13){
			*(strbuf + index) = 0;
			break;
		}
		else{
			putchar(buf_char);
			*(strbuf +index) = buf_char;
			index++;
		}
	}
	if(index == (length-1)){
		*(strbuf +index) = 0;
	}
	return index;
}

void print_total_characters(){
	printf_tiny("\r\nTotal characters since last readout : %u",total_char);
}
void reset_total_characters(){
	total_char = 0;
}
