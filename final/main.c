// main.c
//
// Alex Kelleher and Jack Cusick
// Nov-Dec 2016
// MPS Final Project 
// Morse Code Detection
//
//
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>              // Necessary for printf.
#include "putget.h"             // Necessary for printf
#include "morse.h"
//-------------------------------------------------------------------------------------------
// Global CONSTANTS
//-------------------------------------------------------------------------------------------
#define EXTCLK      22118400    // External oscillator frequency in Hz
#define SYSCLK     	36864000     // Output of PLL derived from (EXTCLK * 5/3)
#define BAUDRATE    115200      // UART baud rate in bps
//#define BAUDRATE  19200       // UART baud rate in bps

__bit timer0_triggered = 0;
//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void PORT_INIT(void);
void SYSCLK_INIT(void);
void UART0_INIT(void);
void TIMER_INIT(void);
void delayCs(unsigned int);
void delayMs(unsigned int);


// xdata has 8096 bytes total, stored internally
static char __xdata buff[1024]; // morse dits and dahs for output
static char __xdata buff3[8];   // dits and dahs from button/sensor - never more than 1 character

char counter;
unsigned int msCounter = 0;
char inputPin;
char bitCounter = 0;

char inputChar;

void TIMER0_ISR (void) __interrupt 1;
//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
    __bit restart = 0;

    char str[30];
    char __xdata ditLength[10];
    char err;
    char mode;
    char i = 0;
    char letter;

    char flagLetter = 1;
    char flagWord = 1; 

	char SFRPAGE_SAVE;
    char state = 1;
    char prevState = 1;
    unsigned int timeStamp;

    char justPrintedSpace = 1;  //  If we have just printed a space, don't print more

    int edgeCounter = -1;       //Number of edges we have seen

    SFRPAGE = CONFIG_PAGE;

    PORT_INIT();                // Configure the Crossbar and GPIO.
    SYSCLK_INIT();              // Initialize the oscillator.
    UART0_INIT();               // Initialize UART0.
    TIMER_INIT();
    MORSE_INIT();               // Set up Morse array

    SFRPAGE = LEGACY_PAGE;
    IT0     = 1;                // /INT0 is edge triggered, falling-edge.


//  SFRPAGE = UART0_PAGE;       // Direct the output to UART0
                                // printf() must set its own SFRPAGE to UART0_PAGE
    printf("\033[2J");          // Erase screen and move cursor to the home position.
    printf("MPS Precise Timer Test\n\n\r");

    //hide cursor
    printf("\033[?25l");

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = CONFIG_PAGE;
    EX0     = 1;                // Enable Ext Int 0 only after everything is settled.
	SFRPAGE = SFRPAGE_SAVE; 	//Restore SFR Page




	while (1)                   
    {	
        printf("Select mode \r\n\t1: ASCII to Morse\r\n\t2: Morse to ASCII \r\n\t3: button to laser\r\n\t4: Chatroom \r\n");
        mode = getchar();
        printf("\r\n");

        if(mode == '1'){    //Convert string to morse
            getString(str, 30);
            printf("Got string: %s\r\n",str);

            err = outputMessage(str, buff);
            if(err){
                printf("String to morse failed.\r\n");
            }
        }
        else if(mode == '2'){   //Convert pushbutton input to Morse code
            printf("go ahead!\r\n");
            inputPin = 0x04; //push button P1.2
            //inputPin = 0x02; //light sensor P1.1 
            while(1){


                state = P1 & inputPin;
                if(state != prevState){ // detect state change
                    timeStamp = csCounter;
                    csCounter = 0;
                    //debounce
                    delayCs(1);
                     if(state){ //falling edge
                        if(edgeCounter == -1){ //first interaction
                            edgeCounter++;
                            prevState = state; //set up edge detect
                            continue;
                        }

                        if(timeStamp < 2*unitTime){ //  dit
                            printf(".");
                            buff3[bitCounter] = '.';
                            justPrintedSpace = 0;
                        } else{                     //  dah
                            printf("-");
                            buff3[bitCounter] = '-';
                            justPrintedSpace = 0;
                        }
                        bitCounter++;
                    }
                    edgeCounter++;
                    prevState = state;
                }
                if(csCounter >= 3*unitTime && state){   //  Letter space
                    buff3[bitCounter] = '\0';
                    letter = parseLetter(buff3);
                    bitCounter = 0;
                }
                if(csCounter >= 5*unitTime && justPrintedSpace == 0 && state){ //Too long for a character space - must be a word space
                    buff3[bitCounter] = '\0';
                    printf(" ");
                    justPrintedSpace = 1;
                }
            }

        }
        else if(mode == '3'){ //Button turns on laser and buzzer when on
			printf("Press any key to exit\r\n");
            inputPin = 0x04; //push button P1.2 
            while(1){
                state = P1 & inputPin;
                if(state){
                    P1 &= 0xFE; //laser off
                    P1 &= 0xF7; //buzzer off
                } else if(!state){
                    P1 |= 0x01; //laser on
                    P1 |= 0x08; //buzzer on
                }
				if(getcharnohang()){    // break on any character input
					break;
				}
            }
        }
        else if(mode == '4'){   //  Transmit and receive
            printf("Enter dit length in ms:\n\r");  //Set unitTime based on user input
            getString(ditLength, 10);
            unitTime = 0;
            i = 0;
            while (ditLength[i] != '\0'){
                unitTime *=10;
                unitTime += ditLength[i] - '0';
                i++;
            }
            unitTime/=10; //to cs
            printf("unit time: %d\r\n",unitTime);

            printf("Enter input device: 0 for ANSII, 1 for push button\r\n");   //Select input device
            inputChar = getchar();

            // inputPin = 0x04; //push button P1.2
            inputPin = 0x02; //light sensor P1.1 
            while(1){
                edgeCounter = -1;

                if(inputChar == '0'){   //Input message
                    printf("Enter message:\n\r");
                    getString(str, 30);
                    printf("Sending: %s\r\n",str);

                    //set prevState to what the first state will be
                    prevState = inputPin;


                    err = outputMessage(str, buff);
                    if(err){
                        printf("String to morse failed.\r\n");
                    }
                } else if(inputChar == '1'){    //If using button, toggle laser + buzzer
                    while(1){
                        state = P1 & 0x04;
                        if(state){
                            P1 &= 0xFE; //laser off
                            P1 &= 0xF7; //buzzer off
                        } else if(!state){
                            P1 |= 0x01; //laser on
                            P1 |= 0x08; //buzzer on
                        }
                        if(getcharnohang()){
                            break;
                        }
                    }
                }
            

                while(1){   //Receive here

                    state = P1 & inputPin;

                    if(state != prevState){ // state change
                        timeStamp = csCounter;
                        csCounter = 0;
                        //  No debounce for laser
                        // delayCs(1);
                        if(state){ //falling edge
                            if(edgeCounter == -1){ //first interaction
                                edgeCounter++;
                                prevState = state;
                                continue;
                            }

                            if(timeStamp < 2*unitTime){ //  dit
                                // printf(".");
                                buff3[bitCounter] = '.';
                                justPrintedSpace = 0;
                            } else{                     //  dah
                                // printf("-");
                                buff3[bitCounter] = '-';
                                justPrintedSpace = 0;
                            }
                            bitCounter++;
                            flagLetter = 1;
                            flagWord = 1;
                        }
                        edgeCounter++;
                        prevState = state;
                    }
                    if(csCounter >= 2*unitTime && state && edgeCounter != -1 && flagLetter){   //  Letter space
                        buff3[bitCounter] = '\0';                        
                        // printf("buff3: %s\r\n",buff3);
                        letter = parseLetter(buff3);
                        bitCounter = 0;   
                        flagLetter = 0;
                    }
                    if(csCounter >= 5*unitTime && justPrintedSpace == 0 && state && edgeCounter != -1 && flagWord){ //Too long for a character spce - must be a word space
                        printf(" ");
                        flagWord = 0; 
                        justPrintedSpace = 1;
                    }
                    if(csCounter >= 10*unitTime && state && edgeCounter != -1){ // Too long - done receiving
                        printf("\r\n");
                        break;
                    }
                }
            }
        }
    }
}

void TIMER_INIT(void){
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = TIMER01_PAGE;


    ET0 = 1;                    // Enable Timer0 Int

    TMOD &= 0xF0;               // Timer0 clear mode bits
    TMOD |= 0x02;               // Timer0 8-bit counter w/ auto reload

    CKCON &= 0xF0;              // Timer0 uses prescaled clock as time base (and clear bits for SCA0 and SCA1)
    CKCON |= 0x02;              // SYCLCK/48 (PLL's output)
    

    TL0 = 0x00;                 // Clear low byte of register T0
    TH0 = 0x00;                 // Clear high byte of register T0 (set auto reload to zero)
    


    TR0 = 1;                    // Start Timer0

	
    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.

}


void delayCs(unsigned int delay){
    unsigned int stopCounter = csCounter+delay;
    while (stopCounter != csCounter); // != instead of > because of overflow every 65s
}

void TIMER0_ISR (void) __interrupt 1 // Corresponds to timer 0 overflow 
{
	counter++;
    if(counter%30 == 0){ //every 30 counts, 10 ms have elapsed
        csCounter++;
        counter = 0;
    }
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

    P1MDOUT |= 0x09;             // P1.0 LED output, P1.1 sensor input, P1.2 push button, P1.3 buzzer output
    P1 &= 0xF6;                  // P1.0 and P1.3 off

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
    // PLL = 5/3 * EXT_CLOCK
    PLL0CN |= 0x01;
    PLL0DIV = 0x03;
    PLL0FLT = 0x03;
    PLL0MUL = 0x05;
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
