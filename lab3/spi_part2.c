//------------------------------------------------------------------------------------
// spi.c
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
#define BAUDRATE    9600              // UART baud rate in bps

//------------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------------
void main(void);
void SYSCLK_INIT(void);
void PORT_INIT(void);
void UART_INIT(void);
void SPI_INIT(void);

void transmitSPI0(char);
char receiveSPI0();


char ISRcount0 = 0;
char ISRcount1 = 0;
char escapeFlag = 0;
//char needToPrintEscapeMessage = 1;
char clearFlag = 0;

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
void main(void)
{
    char c;
    char transmitChar = '\0';
    char receiveChar;
	int i;
    int numCharsTransmited = 0;

    WDTCN = 0xDE;                       // Disable the watchdog timer
    WDTCN = 0xAD;

    PORT_INIT();                        // Initialize the Crossbar and GPIO
    SYSCLK_INIT();                      // Initialize the oscillator
    UART_INIT();                        // Initialize UART0
    SPI_INIT();                         // Initialize SPI0


	//Reset screens
    printf("\033[1;33;44m");            // Bright Yellow text; blue background
    printf("\033[2J");                  // Erase screen & move cursor to home position


    printf("Enter character to transmit:\n\r");

    printf("\033[13;1H");
    printf("Received character:\n\r");
    printf("\033[s"); //save location

    //reset to transmit section
    printf("\033[2;1H");
	while(1){
        //printf1("\r\nwhile_start1\r\n");
        //transmitChar = getcharOrg();
        //printf1("\r\ndone getchar: %c",transmitChar);

        //set scroll sections <ESC>[{SRT};{END}r
        //done in the while loops because one cannot move 12 rows out of scroll region 
        

        transmitChar = getchar();

        //reset scroll regions
        //has to happen aftr get char, so need check to scroll down
        printf("\033[2;12r");
        printf("\033[14;24r");

        //ALMOST THERE, top section doen't scroll

        //move cursor to receive section (saved)
        printf("\033[u");

        //printf("Transmitting..");
        transmitSPI0(transmitChar);

        //printf("Receiving...");
        receiveChar = receiveSPI0();
        printf("%c",receiveChar);
        if(receiveChar == '\r'){
            printf("\n");
        }

        //save new location
        printf("\033[s");
        
        //scroll all (otherwise moving 12 rows doesnt go between regions)
        printf("\033[r");

        printf("\033[u"); //changing scroll moves cursor

        //reset to transmit section (move up 12 rows)
        printf("\033[12A");

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
    XBR0     = 0x06;                    // Enable UART0 and SPI0
    XBR1     = 0x00;
    XBR2     = 0x44;                    // Enable Crossbar and weak pull-up & Enable UART1
    
    //UART1 now on P0.6(TX1) and P0.7(RX1) but i dont think we need for this part so i didn't update
    P0MDOUT  = 0x75;                    // Set TX0 on P0.0 pin, SCK, MOSI, NSS (P0.2, 3 and 5) TX1 on P0.6 pin to push-pull
	//P0MDOUT &= 0xF5;					// Set RX0 on P0.1 pin and RX1 on P0.7 pin to open-drain;
	P0     	 |= 0x82;					// Set RX0 on P0.1 pin and RX1 on P0.7 pin to high impedance mode
    
    SFRPAGE  = SFRPAGE_SAVE;            // Restore SFR page
}

//------------------------------------------------------------------------------------
// SPI_Init
//------------------------------------------------------------------------------------
//
// Configure the SPI
//
void SPI_INIT(void)
{
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;
    SFRPAGE = SPI0_PAGE;

    SPI0CFG = 0x40; // Master mode
    //SPIEN = 1;      // Enable SPI0
    SPI0CN = 0x89;  // Enable SPI0 ()
    SPI0CKR = 0x13; // fSCK = SYSCLCK/(2*(SPI0CKR+1)) = 552960


    SFRPAGE = SFRPAGE_SAVE;
}

//------------------------------------------------------------------------------------
// UART_Init
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


    //all pages -- enable interrupts
    EA = 1;
    //ES0 = 1; //enable UART0 interrupt
    //EIE2 |= 0x40 ;//ES1 = 1; //enable UART1 interrupt

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}


void transmitSPI0(char c){
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;

    SFRPAGE = SPI0_PAGE;

    //1. Enable slave select
	NSSMD0 = 0;

    while(!SPIF);   //2. Check to see if SPI is busy by polling the SPIF flag
    SPIF = 0;
    SPI0DAT = c;    //3. Write data to SPI0DAT

    SFRPAGE = SFRPAGE_SAVE;
}

char receiveSPI0(){
    char c;
	int i;
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;

    SFRPAGE = SPI0_PAGE;

    //1.1 Release slave select 

	NSSMD0 = 1;
    //1.2 wait 1 – 2ms to give the slave time to write data to the register
	for (i = 0; i < 100; i++);

    //2. Write a dummy bit to SPI0DAT
    SPI0DAT = 0xFF;

    while(!SPIF);   //3. Check to see if SPI is busy by polling the SPIF flag
    SPIF = 0;       //4.1 Clear the SPIF flag and 
    c = SPI0DAT;    //4.2 read the data from SPI0DAT
    
    SFRPAGE = SFRPAGE_SAVE;
    return c;
}