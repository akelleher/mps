//------------------------------------------------------------------------------------
// portIO.c
//------------------------------------------------------------------------------------

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
#define SYSCLK      49766400            // Output of PLL derived from (EXTCLK * 9/4)
#define BAUDRATE    115200              // UART baud rate in bps

//------------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------------
void main(void);
void SYSCLK_INIT(void);
void PORT_INIT(void);
void UART0_INIT(void);

// Port 1
__sbit __at 0x90 P1_0;      // Port 1 Pin 0
__sbit __at 0x91 P1_1;      // Port 1 Pin 1
__sbit __at 0x92 P1_2;      // Port 1 Pin 2
__sbit __at 0x93 P1_3;      // Port 1 Pin 3
__sbit __at 0x94 P1_4;      // Port 1 Pin 4
__sbit __at 0x95 P1_5;      // Port 1 Pin 5
__sbit __at 0x96 P1_6;      // Port 1 Pin 6
__sbit __at 0x97 P1_7;      // Port 1 Pin 7

//Port 2
__sbit __at 0xA0 P2_0;   	// Port 2 Pin 0
__sbit __at 0xA1 P2_1; 	    // Port 2 Pin 1
__sbit __at 0xA2 P2_2;  	// Port 2 Pin 2
__sbit __at 0xA3 P2_3;  	// Port 2 Pin 3
__sbit __at 0xA4 P2_4;  	// Port 2 Pin 4
__sbit __at 0xA5 P2_5;  	// Port 2 Pin 5
__sbit __at 0xA6 P2_6; 		// Port 2 Pin 6
__sbit __at 0xA7 P2_7;	    // Port 2 Pin 7


//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
void main(void)
{
    char choice;

    WDTCN = 0xDE;                       // Disable the watchdog timer
    WDTCN = 0xAD;

    PORT_INIT();                        // Initialize the Crossbar and GPIO
    SYSCLK_INIT();                      // Initialize the oscillator
    UART0_INIT();                       // Initialize UART0

    SFRPAGE = UART0_PAGE;               // Direct output to UART0

    // Reset screen
    printf("\033[33;44m");              // Yellow text; blue background
    printf("\033[2J");                  // Erase screen & move cursor to home position
    
    printf("Hello World!\n\r");

    while(1){
		P2 = P1;  //Copy input to output
		printf("p1: %X\tp2: %X\tp1_b: %u%u%u%u %u%u%u%u\tp2_b: %u%u%u%u %u%u%u%u\n\r",P1,P2, P1_7, P1_6, P1_5, P1_4, P1_3, P1_2, P1_1, P1_0, P2_7, P2_6, P2_5, P2_4, P2_3, P2_2, P2_1, P2_0);
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
    OSCICN  = 0x00;

    SFRPAGE = CONFIG_PAGE;
    PLL0CN  = 0x04;
    SFRPAGE = LEGACY_PAGE;
    FLSCL   = 0x10;
    SFRPAGE = CONFIG_PAGE;
    PLL0CN |= 0x01;
    PLL0DIV = 0x04;
    PLL0FLT = 0x01;
    PLL0MUL = 0x09;
    for(i=0; i < 256; i++);
    PLL0CN |= 0x02;
    while(!(PLL0CN & 0x10));
    CLKSEL  = 0x02;

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
    XBR2     = 0x40;                    // Enable Crossbar and weak pull-up
    P0MDOUT |= 0x01;                    // Set TX0 on P0.0 pin to push-pull    

    // Port 1
    //P1MDIN = 0xFF;                    // Set all port 1 pins to digital input
    P1MDOUT = 0x00;                     // Set all port 1 pins to open drain (input)
	P1 = 0xFF;							// Set port 1 pins for input

    // Port 2
    P2MDOUT |= 0xFF;                    // Set all port 2 pins to push-pull (output)
	

    SFRPAGE  = SFRPAGE_SAVE;            // Restore SFR page
}

//------------------------------------------------------------------------------------
// UART0_Init
//------------------------------------------------------------------------------------
//
// Configure the UART0 using Timer1, for <baudrate> and 8-N-1
//
void UART0_INIT(void)
{
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    SFRPAGE = TIMER01_PAGE;
    TMOD   &= ~0xF0;
    TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
    TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
    CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
    TL1     = TH1;
    TR1     = 1;                        // Start Timer1

    SFRPAGE = UART0_PAGE;
    SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
    SSTA0   = 0x10;                     // SMOD0 = 1
    TI0     = 1;                        // Indicate TX0 ready

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}