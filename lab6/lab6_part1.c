//------------------------------------------------------------------------------------
// lab5_part1.c
//------------------------------------------------------------------------------------
//8051 Test program to demonstrate serial port I/O.  This program writes a message on
//the console using the printf() function, and reads characters using the getchar()
//function.  An ANSI escape sequence is used to clear the screen if a '2' is typed. 
//A '1' repeats the message and the program responds to other input characters with
//an appropriate message.
//
//Any valid keystroke turns on the green LED on the board; invalid entries turn it off
//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------
#include <c8051f120.h>
#include <stdio.h>
#include <stdlib.h>
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

void randYesNo(void);
void randTrueFalse(void);
void randDayOfWeek(void);
void randNumber(void);
int getNumber(void);

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

    printf("\033[2J");                  // Erase screen & move cursor to home position
    while(1){
        printf("Magic 8 Ball. Make a choice.\n\r\t1: Yes/No\n\r\t2: True/False\n\r\t3: Day of the week\n\r\t4: Random Number\n\r");
        choice = getchar();
        switch(choice){
            case 1: //  Yes/no
                randYesNo();
                break;
            case 2: //  True/false
                randTrueFalse();
                break;
            case 3: //  Day of the week
                randDayOfWeek();
                break;
            case 4: //  Radndom number
                randNumber();
                break;
            default:
                printf("Not a valid choice - try again\n\r");
                break;
        
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
    P1MDOUT |= 0x40;                    // Set green LED output P1.6 to push-pull

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

void randYesNo(void){
    if(rand()%2){   //Odd numbers are yes, even are no
        printf("Yes\n\r");
    } else {
        printf("No\n\r");
    }
    return;
}
void randTrueFalse(void){
    if(rand()%2){ //Odd numbers are true, even are false
        printf("True\n\r");
    } else {
        printf("False\n\r");
    }
    return;
}
void randDayOfWeek(void){
    const char *daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    printf("%s\r\n", daysOfWeek[rand()%7]);
    return;
}
void randNumber(void){
    int lower;
    int upper;
    int value;
    printf("Enter lower bound\r\n");
    lower = getNumber();
    printf("Enter upper bound\r\n");
    upper = getNumber();

    if (upper < lower){
        value = rand()%(upper-lower)+lower;
        printf("%d", value);
    }

    if (upper = lower){
        printf("%d\r\n", upper); //trivial case
        return;
    }
    
}


int getNumber(void){
    int input_value = 0;
    char char_in;
    int value_of_char;
    printf("Enter number 0-9. Enter key will submit/r/n");
    while(1){
        char_in = getchar();
        if(char_in == 13){   //If we get a carriage return, return the value
            return input_value;
        } else if( (char_in < 48) || (char_in > 57)){   //If char is not a digit, ignore
            printf("Not a digit - ignoring character\r\n");
        } else {
            value_of_char = char_in - 48;   //If we get a valid char - get the numeric value
            input_value *=10;
            input_value += value_of_char;   //add it to the pile
        }
    }
}