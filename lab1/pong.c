//------------------------------------------------------------------------------------
// Hello.c
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
#include "putget.h"
#include <string.h>

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
void printPlayers(void);
void printBorder(void);
void updateScore(void);
void updatePositions(char);
void updateBall(void);

char pixel = '\333';

char screenWidth = 80;
char screenHeight = 25;

char score1 = 0;
char score2 = 0;

char player1Pos = 10;

char player2Pos = 10;

char ballX = 40;
char ballY = 13;

char velX = 0;
char velY = 0;

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
void main(void)
{
    char input;
    char octal = '\333';


    WDTCN = 0xDE;                       // Disable the watchdog timer
    WDTCN = 0xAD;

    PORT_INIT();                        // Initialize the Crossbar and GPIO
    SYSCLK_INIT();                      // Initialize the oscillator
    UART0_INIT();                       // Initialize UART0

    SFRPAGE = UART0_PAGE;               // Direct output to UART0

    printBorder();
    updateScore();

    while(1)
    {
        updateBall();
    	input = getchar();             // TODO: this hangs, it shouldn't
		updatePositions(input);
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

void updateBall(){
    char str[20];

    //dont forget to erase last ball
    char lastX = ballX;
    char lastY = ballY;

    char tenthsX = '0'+(ballX/10);
    char onesX = '0'+(ballX%10);
    
    char tenthsY = '0'+(ballY/10);
    char onesY = '0'+(ballY%10);


    strcpy(str, "\033[__;__H");

    str[2] = tenthsY;
    str[3] = onesY;
    str[5] = tenthsX;
    str[6] = onesX;

    printf(str);
    printf("%c%c",pixel,pixel);

}

void updatePositions(char input){
	if(input == '\167'){ //w
		player1Pos--;
		if(player1Pos<1){
			player1Pos = 1;
		}
	}

	if(input == '\163'){ //s
		player1Pos++;
		if(player1Pos>20){
			player1Pos = 20;
		}
	}

	if(input == '\157'){ //o
		player2Pos--;
		if(player2Pos<1){
			player2Pos = 1;
		}
	}

	if(input == '\154'){ //l
		player2Pos++;
		if(player2Pos>20){
			player2Pos = 20;
		}
	}

	printPlayers();
}


void printPlayers(){
    // Player 1
    char i = 1;

    // char str[20];

    // char tenths = '0'+(player1Pos/10);
    // char ones = '0'+(player1Pos%10);

    printf("\033[1;2H");

    for( i = 1; i <= screenHeight; i++){ //5 is player size
        if(i != 1){
            printf("\n");
        }
        printf("\r");
        printf("\033[1C");
		if(i >= player1Pos && i <= player1Pos+5){
        	printf("%c",pixel);
		} else{
			printf(" ");
		}
    }


    printf("\033[1;78H");

    for( i = 1; i <= screenHeight; i++){ //5 is player size
        if(i != 1){
            printf("\n");
        }
        printf("\r");
        printf("\033[77C");
        if(i >= player2Pos && i <= player2Pos+5){
            printf("%c",pixel);
        } else{
            printf(" ");
        }
    }
}

void printBorder(){
    char i = 0;

    printf("\033[37;40m");              // White text; black background
    printf("\033[2J");                  // Erase screen & move cursor to home position

    // printf("\033[1;38H");               // Position cursor to print title
    // printf("Pong");

    // //Top Border
    // printf("\033[2;1H");                // Position cursor for border
    // for(i = 0; i < screenWidth; i++){   // Top border
    //     printf("%c",pixel);
    // }

    // //Bottom Border
    // printf("\033[25;1H");               // Position cursor for border
    // for(i = 0; i < screenWidth; i++){   // Bottom border
    //     printf("%c",pixel);
    // }

    // //Left Border
    // printf("\033[0;1H");                // Position cursor for border
    // for(i = 1; i < screenHeight; i++){  // Left border
    //     printf("%c\n\r",pixel);
    // }

    // //Right Border
    // printf("\033[80;1H");               // Position cursor for border
    // for(i = 1; i < screenHeight; i++){  // Right border
    //     printf("%c\n",pixel);
    //     printf("\033[80D");             // Move cursor far right
    // }

    //Middle Divider
    printf("\033[1;40H");
    for(i = 1; i < screenHeight; i++){
        printf("|\n\r");
        printf("\033[39C");
    }
    printf("|");

    printPlayers();

    //hide cursor
    printf("\033[?25l");


    //try hiding cursor
    //printf("")

    // updateScore();

}

void updateScore(){
    // Player 1 score
    printf("\033[2;35H");
    printf("%c",score1);

    // Player 2 score
    printf("\033[2;45H");
    printf("%c",score2);
}

void printWinner(){
    //fireworks and such

}