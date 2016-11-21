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
#include <LCD.c>

//------------------------------------------------------------------------------------
// Global Constants
//------------------------------------------------------------------------------------
#define EXTCLK      22118400            // External oscillator frequency in Hz
#define SYSCLK      49766400            // Output of PLL derived from (EXTCLK * 9/4)
#define BAUDRATE    115200              // UART baud rate in bps

//------------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------------


char keypadInterrupt='?';

void main(void);
void SYSCLK_INIT(void);
void PORT_INIT(void);
void UART0_INIT(void);

void keypad_init(void);

void randYesNo(void);
void randTrueFalse(void);
void randDayOfWeek(void);
void randNumber(void);
int getNumber(void);
void printfAndLCD(char *);
void printLCD(char *);
char* itoa(int, char* , int );
void KeypadVector(void) __interrupt 0;
void keypadCleanup(char);

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
    lcd_init();         // initialize the LCD screen
    lcd_cmd(0x3F);      // set display to 2 lines 5x8
                        // (0x30=1 line 5x8, 0x34=1 line 5x10)
    lcd_cmd(0x0C);      // turn on display and cursor
    lcd_cmd(0x01);      // clear display
    
    lcd_clear();
    lcd_home();

    printf("Hello World!\r\n");
    keypad_init();

    // while(1){
    //     printf("Magic 8 Ball. Make a choice.\r\n\t1: Yes/No\r\n\t2: True/False\r\n\t3: Day of the week\r\n\t4: Random Number\r\n");
    //     choice = getchar() - 48;
    //     switch(choice){
    //         case 1: //  Yes/no
    //             randYesNo();
    //             break;
    //         case 2: //  True/false
    //             randTrueFalse();
    //             break;
    //         case 3: //  Day of the week
    //             randDayOfWeek();
    //             break;
    //         case 4: //  Radndom number
    //             randNumber();
    //             break;
    //         default:
    //             printf("Not a valid choice - try again\r\n");
    //             break;
        
    //     }

    // }
    while(1){
        printf("Magic 8 Ball. Make a choice.\r\n\t1: Yes/No\r\n\t2: True/False\r\n\t3: Day of the week\r\n\t4: Random Number\r\n");
        while(keypadInterrupt == '?'){
            //wait for keyinterrupt
        }
        printf("keypadInterrupt: %c\r\n",keypadInterrupt);
        switch(keypadInterrupt){
            case '1': //  Yes/no
                randYesNo();
                break;
            case '2': //  True/false
                randTrueFalse();
                break;
            case '3': //  Day of the week
                randDayOfWeek();
                break;
            case '4': //  Radndom number
                randNumber();
                break;
            default:
                printf("Not a valid choice - try again\r\n");
                break;
        
        }
        keypadInterrupt = '?';

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
    XBR1     = 0x04;
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
        printf("\r\nYes\r\n");
        printLCD("Yes");
    } else {
        printf("\r\nNo\r\n");
        printLCD("No");
    }
    return;
}
void randTrueFalse(void){
    if(rand()%2){ //Odd numbers are true, even are false
        printf("\r\nTrue\r\n");
        printLCD("True");
    } else {
        printf("\r\nFalse\r\n");
        printLCD("False");
    }
    return;
}
void randDayOfWeek(void){
    const char *daysOfWeek[7] = {"Monday\0", "Tuesday\0", "Wednesday\0", "Thursday\0", "Friday\0", "Saturday\0", "Sunday\0"};
    int index = rand()%7;
    printf("\r\n%s\r\n", daysOfWeek[index]);
    printLCD(daysOfWeek[index]);
    return;
}
void randNumber(void){
    int lower;
    int upper;
    int value;
    char numString[20];

    printf("\r\nEnter lower bound\r\n");
    lower = getNumber();
    printf("\r\nEnter upper bound\r\n");
    upper = getNumber();

    if (upper > lower){
        value = rand()%(upper-lower)+lower;
        printf("\r\n%d\r\n", value);
        itoa(value, numString, 10);
        printLCD(numString);
        return;
    } else if (upper == lower){
        printf("\r\n%d\r\n", upper)	; //trivial case
        itoa(upper, numString, 10);
        printLCD(numString);
        return;
    } else {
    	printf("Upper bound is lower than higher bound. Try again\r\n");
    	return;
    }
    
}


int getNumber(void){
    int input_value = 0;
    char char_in;
    int value_of_char;
    printf("Enter digits 0-9. Enter key will submit\r\n");
    while(1){
        char_in = getchar();
        if(char_in == 13){   //If we get a carriage return, return the value
            return input_value;
        } else if( (char_in < 48) || (char_in > 57)){   //If char is not a digit, ignore
            printf("\r\nNot a digit - ignoring character\r\n");
        } else {
            value_of_char = char_in - 48;   //If we get a valid char - get the numeric value
            input_value *=10;
            input_value += value_of_char;   //add it to the pile
        }
    }
}


//TODO
void printfAndLCD(char *str){
    return;
}


void printLCD(char * str){
    unsigned int i, j;
    char spaceCount = 0;
    char counter = 0;

    for(i=0; i<200; i++)// long pause for display 
        for(j=0; j<50000; j++);

    lcd_clear();

    for(i=0; i<200; i++)// long pause for display 
        for(j=0; j<50000; j++);

    //lcd_clear(); 
    // lcd_home();

    lcd_puts(str);

    for(i=0; i<200; i++)// long pause for display 
        for(j=0; j<50000; j++);

    // while (str[counter] != '\0'){
    //     lcd_dat(str[counter]);
    //     for(i=0; i<15; i++) // brief pause for display
    //         for(j=0; j<50000; j++);
    //     counter++;
    // }

    // for(spaceCount = counter; spaceCount < 16; spaceCount++){
    //     lcd_dat(' ');
    //     for(i=0; i<15; i++) // brief pause for display
    //         for(j=0; j<50000; j++);
    // }
}

char* itoa(int value, char* result, int base) {
    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void keypad_init(void){
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    printf("Wrote zeros\r\n");

    SFRPAGE = 0x0F; //P3MDOUT page (P3 is all pages)


    P3MDOUT=0xF0; // hi nibble to push-pull, lo nibble to open-drain
    P3=0x0F; // write 0's to Port 3 hi nibble, lo nibble set for input
    
    SFRPAGE = 0x00; //tcon page (IE is all pages)

    TCON=TCON & 0xFC; // Clear INT0 flag and set for level triggered
    IE=IE|0x81; // Enable all interrupts & enable INT0

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}


void KeypadVector(void) __interrupt 0{
    int i = 0;
    char asciichar = '?';
    char portvalue;
    char keyvalue;

    printf("INTERRUPT INTERRUPT INTERRUPT!\r\n");
    

    for(i = 0; i<10000; i++);  //wait for outputs to stabilize

    keyvalue = P3 & 0x0F; //save keyvalue up here before changing P3

    printf("keyvalue: %c\r\n",keyvalue);

    P3=0x8F; // check if row one (top) was active
    for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
    portvalue = P3 & 0x0F; // read the value of the lower 4 bits
    if (portvalue == 0x0F) // if this row was selected then the value will be 0x0F
    // since the 1 on bit 7 will allow the 4 inputs to be hi
    {
        printf("if 1\r\n");
        if (keyvalue == 0x07) // look at the value of the low 4 bits
        asciichar = '1'; // return the value of the matching key
        else if (keyvalue == 0x0B)
        asciichar = '2';
        else if (keyvalue == 0x0D)
        asciichar = '3';
        else if (keyvalue == 0x0E)
        asciichar = 'A';

        keypadCleanup(asciichar);
        return;
    }

    P3=0x4F; // check if row one (top) was active
    for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
    portvalue = P3 & 0x0F; // read the value of the lower 4 bits
    if (portvalue == 0x0F) // if this row was selected then the value will be 0x0F
    // since the 1 on bit 7 will allow the 4 inputs to be hi
    {
        printf("if 2\r\n");
        if (keyvalue == 0x07) // look at the value of the low 4 bits
        asciichar = '4'; // return the value of the matching key
        else if (keyvalue == 0x0B)
        asciichar = '5';
        else if (keyvalue == 0x0D)
        asciichar = '6';
        else if (keyvalue == 0x0E)
        asciichar = 'B';

        keypadCleanup(asciichar);
        return;
    }


    P3=0x2F; // check if row one (top) was active
    for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
    portvalue = P3 & 0x0F; // read the value of the lower 4 bits
    if (portvalue == 0x0F) // if this row was selected then the value will be 0x0F
    // since the 1 on bit 7 will allow the 4 inputs to be hi
    {
        printf("if 3\r\n");
        if (keyvalue == 0x07) // look at the value of the low 4 bits
        asciichar = '7'; // return the value of the matching key
        else if (keyvalue == 0x0B)
        asciichar = '8';
        else if (keyvalue == 0x0D)
        asciichar = '9';
        else if (keyvalue == 0x0E)
        asciichar = 'C';

        keypadCleanup(asciichar);
        return;
    }


    P3=0x1F; // check if row one (top) was active
    for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
    portvalue = P3 & 0x0F; // read the value of the lower 4 bits
    if (portvalue == 0x0F) // if this row was selected then the value will be 0x0F
    // since the 1 on bit 7 will allow the 4 inputs to be hi
    {
        printf("if 4\r\n");
        if (keyvalue == 0x07) // look at the value of the low 4 bits
        asciichar = '*'; // return the value of the matching key
        else if (keyvalue == 0x0B)
        asciichar = '0';
        else if (keyvalue == 0x0D)
        asciichar = '#';
        else if (keyvalue == 0x0E)
        asciichar = 'D';

        keypadCleanup(asciichar);
        return;
    }




}

void keypadCleanup(char asciichar){
    int i = 0;
    
    //reset P3
    P3=0x0F;
    for(i = 0; i<10000; i++);// wait for output and input pins to stabilize
    

    while (P3 != 0x0F); // wait while the key is still pressed
    for(i = 0; i<10000; i++);// wait for output and input pins to stabilize
    // after key is released
    IE = IE|0x81; // enable INT0 interrupt


    keypadInterrupt = asciichar;   
}