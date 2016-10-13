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
	char SFRPAGE_SAVE;
	SFRPAGE_SAVE = SFRPAGE;

	SFRPAGE = UART0_PAGE;

    while(!TI0); 
    TI0=0;
    SBUF0 = c;
	SFRPAGE = SFRPAGE_SAVE;
	
}





//------------------------------------------------------------------------------------
// putchar1()
//------------------------------------------------------------------------------------
void putchar1(char c)
{
	char SFRPAGE_SAVE;
	SFRPAGE_SAVE = SFRPAGE;

	SFRPAGE = UART1_PAGE;

    while(!TI1); 
    TI1=0;
    SBUF1 = c;

	SFRPAGE = SFRPAGE_SAVE;
}


//------------------------------------------------------------------------------------
// getchar()
//------------------------------------------------------------------------------------
char getchar(void)
{
    char c;
	char SFRPAGE_SAVE;
	SFRPAGE_SAVE = SFRPAGE;

	SFRPAGE = UART0_PAGE;

    while(!RI0);
    RI0 =0;
    c = SBUF0;
// Echoing the get character back to the terminal is not normally part of getchar()
    putchar(c);    // echo to terminal
	putchar1(c);
    
	SFRPAGE = SFRPAGE_SAVE;
	return SBUF0;
}

//------------------------------------------------------------------------------------
// getchar1()
//------------------------------------------------------------------------------------
char getchar1(void)
{
    char c;
	char SFRPAGE_SAVE;
	SFRPAGE_SAVE = SFRPAGE;

	SFRPAGE = UART1_PAGE;
    while(!RI1);
    RI1 =0;
    c = SBUF1;
// Echoing the get character back to the terminal is not normally part of getchar()
    putchar1(c);    // echo to terminal
    putchar(c);
	SFRPAGE = SFRPAGE_SAVE;
	return SBUF1;
}


char getcharnohang(void)
{

    char c;
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;
    SFRPAGE = UART0_PAGE;

    if(RI0){
        RI0 =0;
        c = SBUF0;
        // Echoing the get character back to the terminal is not normally part of getchar()
        putchar(c);    // echo to terminal
        putchar1(c);
        SFRPAGE = SFRPAGE_SAVE;
        return c;
	}
    SFRPAGE = SFRPAGE_SAVE;
	return '\0';
}

char getcharnohang1(void)
{
    char c;
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;
    SFRPAGE = UART1_PAGE;

    if(RI1){
        RI1 =0;
        c = SBUF1;
        // Echoing the get character back to the terminal is not normally part of getchar()
        putchar(c);    // echo to terminal
        putchar1(c);
        SFRPAGE = SFRPAGE_SAVE;
        return c;
    }
    SFRPAGE = SFRPAGE_SAVE;
    return '\0';
}


void printf1(char * str){
    char i = 0;
    // for( i = 0; i< len; i++){
    //     putchar1(str[i]);
    // }
    while(str[i] != '\0'){
        putchar1(str[i]);
        i++;
    }
}