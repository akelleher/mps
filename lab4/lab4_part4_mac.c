// IntrptEx.c
//
// 8051 Interrupt Example Program
// Alexey Gutin
// March 2, 2007
//
// This program uses an interrupt to call the ISR handler
// function, SWR_ISR(), when the /INT0 line is grounded.
// Each time the signal makes a low transition, an interrupt will be
// generated.  If the line is held down, the SWR_ISR()
// function will only be executed once, and not be called
// again unless the line is released, and grounded again.
//
// /INT0 is configured to be on P0.2
// UART0 is used to communicate to the user through ProCOMM or SecureCRT
//
// This code was written and tested using the SiLabs IDE V4.90
// and SDCC V3.5.0.
//
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>              // Necessary for printf.
#include "putget.h"             // Necessary for printf
//-------------------------------------------------------------------------------------------
// Global CONSTANTS
//-------------------------------------------------------------------------------------------
#define EXTCLK      22118400    // External oscillator frequency in Hz
#define SYSCLK      49766400    // Output of PLL derived from (EXTCLK * 9/4)
#define BAUDRATE    115200      // UART baud rate in bps
//#define BAUDRATE  19200       // UART baud rate in bps

__bit SW2press = 0;
//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void PORT_INIT(void);
void SYSCLK_INIT(void);
void UART0_INIT(void);
void ADC_INIT(void);
void start_AD_Conversion(void);
unsigned int get_AD_Conversion(void);
void DAC0_write(unsigned int);
void DAC_INIT(void);
unsigned int AD_Conversion(void);
void MAC_INIT(void);

void SW2_ISR (void) __interrupt 0;
//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
    __bit restart = 0;
//    char character;
//    unsigned int delay1, delay2 = 0;
//    unsigned int randnum = 0;
//    unsigned int ones, tenths = 0;
    char SFRPAGE_SAVE;

    unsigned int ADC_read;
    unsigned int DAC_out = 0;

    int xk = 0;
    int xk_test = 3000;
    int xkminus1 = 0;
    int xkminus2 = 0;
    unsigned int yk = 0;
    unsigned int ykminus1 = 0;
    int dummy;

    double volt;
    double volt2;

    int highyk;
    int lowyk;


    SFRPAGE = CONFIG_PAGE;

    PORT_INIT();                // Configure the Crossbar and GPIO.
    SYSCLK_INIT();              // Initialize the oscillator.
    UART0_INIT();               // Initialize UART0.
    ADC_INIT();                 // Initialize ADC.
    DAC_INIT();					// Initialize DAC0.
    MAC_INIT();

    SFRPAGE = LEGACY_PAGE;
    IT0     = 1;                // /INT0 is edge triggered, falling-edge.

//  SFRPAGE = UART0_PAGE;       // Direct the output to UART0
                                // printf() must set its own SFRPAGE to UART0_PAGE
    printf("\033[2J");          // Erase screen and move cursor to the home position.
    
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = CONFIG_PAGE;
    EX0     = 1;                // Enable Ext Int 0 only after everything is settled.
    SFRPAGE = SFRPAGE_SAVE;     //Restore SFR Page


    printf("Hello World!\n\r");

    while (1)                   
    {   

        SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
        SFRPAGE = MAC0_PAGE;

        //1. Start a new conversion

        //2. Update previous values

        ykminus1 = yk;
        xkminus2 = xkminus1;
        xkminus1 = xk;

        //3. Clear MAC acc and set MAC mode (set in init)
        MAC0CF |= 0x08; //clear
        MAC0CF |= 0x02;  // Fraction mode

        //4. Get the new sample
        xk = AD_Conversion() - 2048;


        //volt = 2.4*(xk/4096.0);
        //printf_fast_f("Cur: 0%x\t%1.6f",xk,volt);


        //5. Subtract the 1.5V offset
        //xk -= 2560;     //offset is 1.5V: 1.5/2.4*2^12 = 2560

        //printf("\tAfter offset: %x\r\n",xk);



        //6. Load MAC0A with 0.31250000 hexadecimal equivalent or scaled integer value (16-bit)
        MAC0AH = 0x28;
        MAC0AL = 0x00;


        //7. Load MAC0BH & MAC0BL with the 12 bits of current sample (k)
        MAC0BH = xk >> 8;
        MAC0BL = xk; //start multiply + accumulate

        //wait for conversion
        // dummy = 1+2;
        // dummy = 3+4;

        //8. Load MAC0BH & MAC0BL with the 12 bits of second previous sample (k-2)
        MAC0BH = xkminus2 >> 8;
        MAC0BL = xkminus2; //start multiply + accumulate

        // wait for conversion
        // dummy = 1+2;
        // dummy = 3+4;

        //9. Load MAC0A with 0.24038462 hexadecimal equivalent or scaled integer value (16-bit)
        MAC0AH = 0x1e;// MAC0AH = 0x28; //MAC0A = 0.3125
        MAC0AL = 0xc4;

        //10. Load MAC0BH & MAC0BL with the 12 bits of first previous sample (k-1)
        MAC0BH = xkminus1 >> 8;
        MAC0BL = xkminus1; //start multiply + accumulate

        //wait for conversion
        // dummy = 1+2;
        // dummy = 3+4;
        
        //11. Load MAC0A with 0.29687500 hexadecimal equivalent or scaled integer value (16-bit)
        MAC0AH = 0x26;
        MAC0AL = 0x00;

        //12. Load MAC0BH & MAC0BL with the 12 bits of previous output (k-1)
        MAC0BH = ykminus1 >> 8;
        MAC0BL = ykminus1; //start multiply + accumulate

        //wait for conversion
        // dummy = 1+2;
        // dummy = 3+4;

        //13. Do left or right bit shifts to align 12-bit answer on byte boundary

        //14. Wait for conversion
        SFRPAGE = MAC0_PAGE;
        //SFRPAGE = MAC0_PAGE;




        //15. Get the signed 16-bit results from MAC0ACC3 & MAC0ACC2 or 2 & 1 in integer mode
        lowyk = MAC0ACC2;
        highyk = MAC0ACC3;
        yk = (highyk << 8 | lowyk) + 2048;

        //16. Add back in the 1.5V offset & scale (may be also done using the MAC if you are clever)
        // yk += 2560; //add offset back in

        //volt2 = 2.4*(xk/4096.0);
        //printf_fast_f("\tGain of -1 = %1.6f\r\n");

        //printf("xk: %d\txk-2: %d,\tyk: %u\r\n",xk, xkminus2, yk);

        //17. Output final result to DAC0
        DAC0_write(yk);

        SFRPAGE = SFRPAGE_SAVE;

        //18. Repeat sequence
    }

    //printf("dummy is: %d",dummy);
}
//-------------------------------------------------------------------------------------------
// Interrupt Service Routines
//-------------------------------------------------------------------------------------------
// NOTE: this is an example of what NOT to do in an interrupt handler. No I/O should be done
// in ISRs since I/O is very slow and the handler must execute very quickly.
//
// This routine stops Timer0 when the user presses SW2.
//
void SW2_ISR (void) __interrupt 0   // Interrupt 0 corresponds to vector address 0003h.
// the keyword "interrupt" defines this as an ISR and the number is determined by the 
// Priority Order number in Table 11.4 in the 8051 reference manual.
{
    SW2press = 1;
    //printf("/INT0 has been grounded here!\n\n\r");
}

//-------------------------------------------------------------------------------------------
// PORT_Init
//-------------------------------------------------------------------------------------------
//
// Configure the Crossbar and GPIO ports
//
void PORT_INIT(void)
{
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = CONFIG_PAGE;
    WDTCN   = 0xDE;             // Disable watchdog timer.
    WDTCN   = 0xAD;
    EA      = 1;                // Enable interrupts as selected.

    XBR0    = 0x04;             // Enable UART0.
    XBR1    = 0x04;             // /INT0 routed to port pin.
    XBR2    = 0x40;             // Enable Crossbar and weak pull-ups.

    P0MDOUT = 0x01;             // P0.0 (TX0) is configured as Push-Pull for output.
            // P0.1 (RX0) is configure as Open-Drain input.
            // P0.2 (SW2 through jumper wire) is configured as Open_Drain for input.
    P0      = 0x06;             // Additionally, set P0.0=0, P0.1=1, and P0.2=1.

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.
}

//-------------------------------------------------------------------------------------------
// SYSCLK_Init
//-------------------------------------------------------------------------------------------
//
// Initialize the system clock
//
void SYSCLK_INIT(void)
{
    int i;

    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = CONFIG_PAGE;
    OSCXCN  = 0x67;             // Start external oscillator
    for(i=0; i < 256; i++);     // Wait for the oscillator to start up.
    while(!(OSCXCN & 0x80));    // Check to see if the Crystal Oscillator Valid Flag is set.
    CLKSEL  = 0x01;             // SYSCLK derived from the External Oscillator circuit.
    OSCICN  = 0x00;             // Disable the internal oscillator.

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
    CLKSEL  = 0x02;             // SYSCLK derived from the PLL.

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.
}

//-------------------------------------------------------------------------------------------
// UART0_Init
//-------------------------------------------------------------------------------------------
//
// Configure the UART0 using Timer1, for <baudrate> and 8-N-1.
//
void UART0_INIT(void)
{
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = TIMER01_PAGE;
    TMOD   &= ~0xF0;
    TMOD   |=  0x20;            // Timer1, Mode 2: 8-bit counter/timer with auto-reload.
    TH1     = (unsigned char)-(SYSCLK/BAUDRATE/16); // Set Timer1 reload value for baudrate
    CKCON  |= 0x10;             // Timer1 uses SYSCLK as time base.
    TL1     = TH1;
    TR1     = 1;                // Start Timer1.

    SFRPAGE = UART0_PAGE;
    SCON0   = 0x50;             // Set Mode 1: 8-Bit UART
    SSTA0   = 0x10;             // UART0 baud rate divide-by-two disabled (SMOD0 = 1).
    TI0     = 1;                // Indicate TX0 ready.

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.
}


void ADC_INIT(void){
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = ADC0_PAGE;

    REF0CN = 0x03;      // Set converter to use internal reference (2.4V)
    ADC0CN = 0x80;      // Enable Converter
    ADC0CF |= 0x00;     // Set gain to 1

    SFRPAGE = SFRPAGE_SAVE;
}

void DAC_INIT(void){
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = DAC0_PAGE;

	DAC0CN = 0x80;

	SFRPAGE=SFRPAGE_SAVE;
}

void start_AD_Conversion(void){
    int adcReturn = 0;
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = ADC0_PAGE;

    AMX0SL = 0;         // Set pin to convert with AMX1SL to Pin 0 (P1.0)
    AMX0CF = 0;
    ADC0CN &= ~0x20;    // Clear conversion bit
    ADC0CN |= 0x10;     // Start conversion
    SFRPAGE = SFRPAGE_SAVE;
}

unsigned int get_AD_Conversion(void){

	unsigned int adcReturn;
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = ADC0_PAGE;

    while((ADC0CN | 0xEF) == 0xFF){     // Wait for conversion to complete
        //wait
    }

    adcReturn = (ADC0H << 8) + ADC0L;
    SFRPAGE = SFRPAGE_SAVE;

    return adcReturn;    // Return the result
}

void DAC0_write(unsigned int writeValue){
	char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = DAC0_PAGE;

    DAC0L = writeValue;
    DAC0H = writeValue >> 8; 


    SFRPAGE = SFRPAGE_SAVE;
}

void MAC_INIT(void){
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = MAC0_PAGE;

    MAC0CF = 0x0A;  // Fraction mode

    //3. Clear MAC acc and set MAC mode
    //MAC0CF |= 0x08; //clear


    SFRPAGE = SFRPAGE_SAVE;
}


unsigned int AD_Conversion(void){
    unsigned int adcReturn = 0;
    char SFRPAGE_SAVE;
    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = ADC0_PAGE;

    AMX0SL = 0;         // Set pin to convert with AMX1SL to Pin 0 (P1.0)
    AMX0CF = 0;
    ADC0CN &= ~0x20;    // Clear conversion bit
    ADC0CN |= 0x10;     // Start conversion
    while((ADC0CN | 0xEF) == 0xFF){     // Wait for conversion to complete
        //wait
    }

    adcReturn = (ADC0H << 8) + ADC0L;

    SFRPAGE = SFRPAGE_SAVE;

    return adcReturn;    // Return the result
}