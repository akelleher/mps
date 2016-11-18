//------------------------------------------------------------------------------------
// memory_part_3.c
//------------------------------------------------------------------------------------
// Title:               Microcontroller Lab 5 Task 3
// Author:              Alex Kelleher
// Date Created:        11.07.2016
// Date Last Modified:  11.11.2016
// 
// Description: This software writes a character to a specific address in external memory
//              Used for 4 bit data
//
// Target:              C8051F120
// Tool Chain:          KEIL C51
//
// 
// NOTES:
// (1) /WR    = P4.7 (CNTRL signal)
// (2) /RD    = P4.6 (CNTRL signal)
// (3) D0-D7  = P7.0-P7.7 (DATA bus)
// (4) A0-A7  = P6.0-P6.7 (ADR bus lo byte)
// (5) A8-A15 = P5.0-P5.7 (ADR bus hi byte)
//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------
#include <c8051f120.h>
#include <stdio.h>
#include "putget.h"

//------------------------------------------------------------------------------------
// Global Constants
//------------------------------------------------------------------------------------
#define EXTCLK      22118400    // External oscillator frequency in Hz
#define SYSCLK      22118400    // Output of crystal oscillator
#define BAUDRATE    28800       // UART baud rate in bps

//------------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------------
void main(void);
void SYSCLK_INIT(void);
void PORT_INIT(void);
void UART0_INIT(void);
unsigned char _sdcc_external_startup(void);

//------------------------------------------------------------------------------------
// _sdcc_external_startup
//------------------------------------------------------------------------------------
//
// This is special function called by the system BEFORE main() is executed
//
// Disable watchdog timer before normal initialization - needed for memory
//
unsigned char _sdcc_external_startup(void)
{
    WDTCN = 0xDE;   // Disable the watchdog timer
    WDTCN = 0xAD;

    return 0;       // init everything else normally
}

//------------------------------------------------------------------------------------
// parity
//------------------------------------------------------------------------------------
//
// This function returns the even parity of the passed in number
// num is assumed to be a 3 bit number (0x0 - 0x7)
unsigned char parity(unsigned char num){
    char returnVal = 0;
    // XOR the two least significant bits
    returnVal = (num & 0x01)^((num>>1) & 0x01);
    // XOR most significant bit
    returnVal ^= ((num>>2) & 0x01);
    return returnVal;
}

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
void main(void)
{
    // counters
	int i = 0;
    int j = 0;

    // variable for referencing internal and external RAM
    volatile __xdata unsigned char *ext_ram;

    // variable for storing read/write errors (stored internally)
	unsigned static char __xdata count[512];	

    unsigned int count_index = 0;
    unsigned char value_to_save = 0x01;

    // initialize to external Am91L14 RAM
	ext_ram = (__xdata unsigned char *)(0x4000);

    SYSCLK_INIT();          // Initialize the oscillator
    PORT_INIT();            // Initialize the Crossbar and GPIO
    UART0_INIT();           // Initialize UART0

    SFRPAGE = UART0_PAGE;   // Direct output to UART0

    printf("\033[2J");     // Erase ANSI terminal & move cursor to home position
    printf("Memory test\n\n\r");

    while(1)
    {

        printf("num: %u\r\n",value_to_save);
        printf("parity: %u\r\n", parity(value_to_save));

        //parity bit is most significant bit, least significant 3 bits are the value
        value_to_save = parity(value_to_save)<<3 | value_to_save;

        printf("value to save: %u", value_to_save);

        //wait for user input (allows time for user to experiment with wires and intentional errors)
        getchar();

        //write data to all address slots of the Am91L14 and 6 slots past (to ensure those do not work)
        for(i = 0; i < 0x405; i++){  //10 address bits, 1024 slots of 0x400 (read 5 past to show it works)
			ext_ram[i] = value_to_save;
		}

        //wait for user input
        getchar();

        //read 
        for(i = 0; i < 0x405; i++){ //9 address pins, 512 memory locations
            printf("Address 0x%x, wrote: 0x%x\tread: 0x%x", i+0x4000, value_to_save, ext_ram[i] & 0x0F); //16384 is 0x4000 in decimal 
            if(parity(ext_ram[i] & 0x07) != ((ext_ram[i] & 0x0F) >> 3)){ //if parity bit doesn't equal even parity of data bits -> parity error
                printf("\tPARITY ERROR!");
            }
            printf("\r\n");
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

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page SFRPAGE = CONFIG_PAGE;
    SFRPAGE = CONFIG_PAGE;

    OSCXCN = 0x67;              // Start ext osc with 22.1184MHz crystal
    for(i=0; i < 3000; i++);    // Wait for the oscillator to start up
    while(!(OSCXCN & 0x80));
    CLKSEL = 0x01;              // Switch to the external crystal oscillator
    OSCICN = 0x00	;              // Disable the internal oscillator

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
}

//------------------------------------------------------------------------------------
// PORT_Init
//------------------------------------------------------------------------------------
//
// Configure the Crossbar and GPIO ports
//
void PORT_INIT(void)
{
    char SFRPAGE_SAVE = SFRPAGE;    // Save Current SFR page
    SFRPAGE = CONFIG_PAGE;

    XBR0 = 0x04;        // Enable UART0
    XBR1 = 0x00;
    XBR2 = 0x40;        // Enable Crossbar and weak pull-up

    P0MDOUT |= 0x01;    // Set TX0 pin to push-pull
    P4MDOUT = 0xFF;     // Output configuration for P4 all pushpull
    P5MDOUT = 0xFF;     // Output configuration for P5 pushpull EM addr
    P6MDOUT = 0xFF;     // Output configuration for P6 pushpull EM addr
    P7MDOUT = 0xFF;     // Output configuration for P7 pushpull EM data

    P5 = 0xFF;
    P6 = 0xFF;
    P7 = 0xFF;

// EMI_Init, split mode with no banking

    SFRPAGE = EMI0_PAGE;
    EMI0CF = 0x3b;              //34
    EMI0TC = 0xFF;

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
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

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page
    SFRPAGE = TIMER01_PAGE;

    TCON = 0x40;
    TMOD &= 0x0F;
    TMOD |= 0x20;               // Timer1, Mode 2, 8-bit reload
    CKCON |= 0x10;              // Timer1 uses SYSCLK as time base
// TH1 = 256 - SYSCLK/(BAUDRATE*32)  Set Timer1 reload baudrate value T1 Hi Byte
    TH1 = 0xE8;                 // 0xE8 = 232
    TR1 = 1;                    // Start Timer1

    SFRPAGE = UART0_PAGE;
    SCON0 = 0x50;               // Mode 1, 8-bit UART, enable RX
    SSTA0 = 0x00;               // SMOD0 = 0, in this mode
                                // TH1 = 256 - SYSCLK/(baud rate * 32)

    TI0 = 1;                    // Indicate TX0 ready

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
}