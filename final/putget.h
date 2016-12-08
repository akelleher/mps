//------------------------------------------------------------------------------------
// putget.h
//------------------------------------------------------------------------------------
// Title:               Microcontroller Development: putchar() & getchar() functions.
// Author:              Dan Burke
// Date Created:        03.25.2006
// Date Last Modified:  03.25.2006
// 
// Description:         http://chaokhun.kmitl.ac.th/~kswichit/easy1/easy1_3.html
// 
//
// Target:              C8051F120
// Tool Chain:          KEIL C51
#include <stdio.h>              // Necessary for printf and NULL.
#include <c8051f120.h>          // SFR declarations.
#include <stdlib.h>
#include <string.h>
//------------------------------------------------------------------------------------
// putchar()
//------------------------------------------------------------------------------------
void putchar(char c)
{
    while(!TI0); 
    TI0=0;
    SBUF0 = c;
}

//------------------------------------------------------------------------------------
// getchar()
//------------------------------------------------------------------------------------
char getchar(void)
{
    char c;
    while(!RI0);
    RI0 =0;
    c = SBUF0;
// Echoing the get character back to the terminal is not normally part of getchar()
    putchar(c);    // echo to terminal
    return SBUF0;
}

void getString(char * buff, char len){
	char tmp = ' ';
	char counter = 0;
	while(1){ //ENTER
		if(counter == len - 1){
			break;
		}
		tmp = getchar();
		if(tmp == 13){ // ENTER
			break;
		}
		buff[counter] = tmp;
		counter++;
	}
	buff[counter] = '\0';
}