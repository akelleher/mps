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

#include <c8051f120.h>

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
    while(!RI0); //is this equivalent to while(){} or while(){RIO=0;}, it must be empty
    RI0 =0;
    c = SBUF0;
// Echoing the get character back to the terminal is not normally part of getchar()
    //putchar(c);    // echo to terminal
    return SBUF0;
}


char getCharNoHang(void){
    if(RI0){
		RI0 = 0;
    	return SBUF0;
    }
    else{
    	return '\007'; //cant pass empty '' so will use bell to denote null
    }
}