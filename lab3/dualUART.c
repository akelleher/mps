//------------------------------------------------------------------------------------
// dualUART.c
//------------------------------------------------------------------------------------
//
// 8051 Dual Serial Connection
// John Cusick
// October 11, 2016
//
// This program uses both UART0 and UART1 to simultaneously
// communicate with two serial connections.
//
// UART0 & UART1 is used to communicate to the user through ProCOMM or SecureCRT
//
// This code was written and tested using the SiLabs IDE V4.90
// and SDCC V3.5.0.
//
//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------
#include <c8051f120.h>
#include <stdio.h>
#include "putget.h"

//------------------------------------------------------------------------------------
// Global Constants
//------------------------------------------------------------------------------------
#define EXTCLK      22118400            // External oscillator frequency in Hz
//#define SYSCLK      49766400            // Output of PLL derived from (EXTCLK * 9/4)
#define SYSCLK      22118400
#define BAUDRATE    115200              // UART baud rate in bps

//------------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------------
void main(void);
void SYSCLK_INIT(void);
void PORT_INIT(void);
void UART_INIT(void);

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
void main(void)
{
    char choice1;
    char choice2;

    WDTCN = 0xDE;                       // Disable the watchdog timer
    WDTCN = 0xAD;

    PORT_INIT();                        // Initialize the Crossbar and GPIO
    SYSCLK_INIT();                      // Initialize the oscillator
    UART_INIT();                        // Initialize UART0

	//Reset screens
    printf("\033[1;33;44m");            // Bright Yellow text; blue background
    printf("\033[2J");                  // Erase screen & move cursor to home position
    //printf("\033[1;33;44m");              // Yellow text; blue background
    
    // putchar1('\033');
    // putchar1('[');
    // putchar1('1');
    // putchar1(';');
    // putchar1('3');
    // putchar1('3');
    // putchar1(';');
    // putchar1('4');
    // putchar1('4');
    // putchar1('m');

    // putchar1('\033');
    // putchar1('[');
    // putchar1('2');
    // putchar1('J');

    printf1("\033[1;33;44m");           // Bright Yellow text; blue background
    printf1("\033[2J");                 // Erase screen & move cursor to home position

	while(1){
        choice1 = getcharnohang();
		choice2 = getcharnohang1();

        if(choice1 == \033 || choice2 == \033){
            //clear screens
            printf("\033[1;33;44m");    // Bright Yellow text; blue background
            printf("\033[2J");          // Erase screen & move cursor to home position
            printf1("\033[1;33;44m");   // Bright Yellow text; blue background
            printf1("\033[2J");         // Erase screen & move cursor to home position

            //print message
            printf("\033[12;12HEscape key pressed, execution halted, press any key to resume");
            printf1("\033[12;12HEscape key pressed, execution halted, press any key to resume");


            //wait for any input
            choice1 = '\0';
            choice2 = '\0';
            while(choice1 == '\0' && choice2 == '\0'){
                choice1 = getcharnohang();
                choice2 = getcharnohang1();
            }

            //clear screens, continue execution
            printf("\033[1;33;44m");    // Bright Yellow text; blue background
            printf("\033[2J");          // Erase screen & move cursor to home position
            printf1("\033[1;33;44m");   // Bright Yellow text; blue background
            printf1("\033[2J");         // Erase screen & move cursor to home position

        }
	}

}

//------------------------------------------------------------------------------------
// SYSCLK_Init
//------------------------------------------------------------------------------------
//
// Initialize the system clock to use a 22.1184MHz crystal as its clock source
//
void SYSCLK_INIT(void)
{
    int i;
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    SFRPAGE = CONFIG_PAGE;
    OSCXCN  = 0x67;                     // Start ext osc with 22.1184MHz crystal
    for(i=0; i < 256; i++);             // Wait for the oscillator to start up
    while(!(OSCXCN & 0x80));
    CLKSEL  = 0x01;
    OSCICN  &= 0x7F;  //disable internal oscillator

    // SFRPAGE = CONFIG_PAGE;
    // PLL0CN  = 0x04;
    // SFRPAGE = LEGACY_PAGE;
    // FLSCL   = 0x10;
    // SFRPAGE = CONFIG_PAGE;
    // PLL0CN |= 0x01; //0x00 is <25MHz
    // PLL0DIV = 0x04;
    // PLL0FLT = 0x01;
    // PLL0MUL = 0x09;
    // for(i=0; i < 256; i++);
    // PLL0CN |= 0x02;
    // while(!(PLL0CN & 0x10));
    // CLKSEL  = 0x02;

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}

//------------------------------------------------------------------------------------
// PORT_Init
//------------------------------------------------------------------------------------
//
// Configure the Crossbar and GPIO ports
//
void PORT_INIT(void)
{    
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    SFRPAGE  = CONFIG_PAGE;
    XBR0     = 0x04;                    // Enable UART0
    XBR1     = 0x00;
    XBR2     = 0x44;                    // Enable Crossbar and weak pull-up & Enable UART1
    P0MDOUT  = 0x05;                    // Set TX0 on P0.0 pin and TX1 on P0.2 pin to push-pull
	//P0MDOUT &= 0xF5;					// Set RX0 on P0.1 pin and RX1 on P0.3 pin to open-drain;
	P0     	 = ~0x05;					// Set RX0 on P0.1 pin and RX1 on P0.3 pin to high impedance mode
    
    SFRPAGE  = SFRPAGE_SAVE;            // Restore SFR page
}

//------------------------------------------------------------------------------------
// UART0_Init
//------------------------------------------------------------------------------------
//
// Configure the UART0 using Timer1, for <baudrate> and 8-N-1
//
void UART_INIT(void)
{
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    //Timer 1 used by UART1
    SFRPAGE = TIMER01_PAGE;
    //TMOD   &= ~0xF0;
    TMOD   =  0x20;                    // Timer1, Mode 2, 8-bit reload
    //TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
    TH1 =  0xA0; //A0						// autoreload necessary for 115200 buad rate (see p.307 manual)
	CKCON  |= 0x10;                     // Timer1 uses SYSCLK (22.1Mhz) as time base
    TL1     = TH1;
    TR1     = 1;                        // Start Timer1

    //Timer 2 used by UART0
    SFRPAGE = TMR2_PAGE;
    TMR2CN  = 0x00; // Timer uses TMR2CF clock and auto reload (16 bit mode)
    TMR2CF  = 0x08; // Timer 2 uses SYSCLK //0x08

    RCAP2H  = 0xFF;
    RCAP2L  = 0x70; //27
    
    TMR2H   = 0xFF;                        // autoreload necessary for 9600 buad rate (see p.307 manual)
    TMR2L   = 0x70; 
    TR2     = 1;                        // Start Timer2

    // UART 0 -- 9600 baud
    SFRPAGE = UART0_PAGE;
    SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
    SSTA0   |= 0x05;                     // UART0 triggered by timer 2
    TI0     = 1;                        // Indicate TX0 ready

    //UART1 -- 115200 baud
	SFRPAGE = UART1_PAGE;
	SCON1 	= 0x30; //10				// 8-bit UART, enable RX
	//no SSTA1
	TI1 	= 1;						// Indicate TX1 ready

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}