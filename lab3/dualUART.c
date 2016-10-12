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
#define SYSCLK      49766400            // Output of PLL derived from (EXTCLK * 9/4)
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
    char choice;

    WDTCN = 0xDE;                       // Disable the watchdog timer
    WDTCN = 0xAD;

    PORT_INIT();                        // Initialize the Crossbar and GPIO
    SYSCLK_INIT();                      // Initialize the oscillator
    UART_INIT();                       // Initialize UART0

    SFRPAGE = UART0_PAGE;               // Direct output to UART0
	//SFRPAGE = UART1_PAGE;				// Direct output to UART1

	// Reset screen
    printf("\033[33;44m");              // Yellow text; blue background
    printf("\033[2J");                  // Erase screen & move cursor to home position
    printf("\033[33;44m");              // Yellow text; blue background (twice for escape bug)

	
	while(1){
		choice = getchar();
	}



    
    // Store location for unprintable notifaction
    printf("\033[12;0H");               // Position cursor to print unprintables
    printf("\033[s");                   // Store current location

    // Print end instructions
    printf("\033[2;25H");               // Position cursor to print instructions
    printf("Type <ESC> to end the program.\n\n\r");
    
    // Print printable character prompt (leave a space for the actual character)
    printf("\033[6;0H");                // Position cursor to print Keyboard character info
    printf("The keyboard character is  .");

    printf("\033[12;25r");              // Set scrollable region

    while(1)
    {
        // Setup cursor for printable character output
        printf("\033[6;27H");           // Position cursor where keyboard character is to be displayed
        printf("\033[37m");             // White text

        choice = getchar();

        P1 |= 0x40;                     // Turn green LED on (alert user program is on)

        // If they pressed escape, end the program.
        if (choice == '\033'){
            return;
        }

        // If not a printable characters
        if (!(choice >= '\040' && choice <= '\176')){ 
            printf("\033[5;33;44m");        // Blinking text; yellow text; blue background
            printf("\033[u");               // Position cursor to print Keyboard character info (using saved location)

            // Print 'not printable' warning, some things to Note:
            // $%02X prints captail hexadecimal with two digits 
            // \033[4m underline 'not printable'
            // \033[0;5;33;44m clear formatting and set to blinking text; yellow text; blue background
            // \n\r move cursor to start of next line
            printf("The keyboard character $%02X is \033[4m'not printable'\033[0;5;33;44m.\n\r", choice);

            printf("\007");                 // Sound bell

            // Note: must be done on separate lines (bug: would default to black background)
            printf("\033[0m");              // Clear formatting
            printf("\033[33;44m");          // Yellow text; blue background

            // The new saved location is at the start of the next line in the scrollable section (from the \n\r)
            printf("\033[s");               // Overwrite saved cursor info

            // A space is printed in the printable character location when an unprintable character is pressed because
            // some unprintable characters have built in graphical depictions which we do not wish to display
            printf("\033[6;27H ");          // Move cursor and print space in the printable character location

        }

        // IF a printable character was entered, no need to print as it is already echo'd upon typing,
        // just have to ensure the cursor is in the right location and text is white (done at start of while)

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
    XBR2     = 0x44;                    // Enable Crossbar and weak pull-up & Enable UART1
    P0MDOUT |= 0x05;                    // Set TX0 on P0.0 pin and TX1 on P0.2 pin to push-pull
	P0MDOUT &= 0xF5;					// Set RX0 on P0.1 pin and RX1 on P0.3 pin to open-drain;
	P0     	|= 0x0A;					// Set RX0 on P0.1 pin and RX1 on P0.3 pin to high impedance mode
    P1MDOUT |= 0x40;                    // Set green LED output P1.6 to push-pull

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

    SFRPAGE = TIMER01_PAGE;
    TMOD   &= ~0xF0;
    TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
    TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
    CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
    TL1     = TH1;
    TR1     = 1;                        // Start Timer1

    SFRPAGE = UART0_PAGE;
    SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
    //SSTA0   = 0x10;                     // SMOD0 = 1
    TI0     = 1;                        // Indicate TX0 ready
	
	//WITHOUT SSTA0: 57600 is the baudrate

	SFRPAGE = UART1_PAGE;
	SCON1 	= 0x10;						// 8-bit UART, enable RX
	//no SSTA1
	TI1 	= 1;						// Indicate TX1 ready

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}