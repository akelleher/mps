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
#define SYSCLK      36864000            // Output of PLL derived from (EXTCLK * 5/3)
#define BAUDRATE    115200              // UART baud rate in bps

//------------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------------
void main(void);
void SYSCLK_INIT(void);
void PORT_INIT(void);
void UART0_INIT(void);
void TIMER_INIT(void);
void TIMER0_ISR (void) __interrupt 1;
void advanceBall(void);
void printPlayers(void);
void printBorder(void);
void updateScore(void);
void updatePositions(char);
void updateBall(void);
char goalScored(void);
void gameOver(void);
void nextPoint(void);
void printWinner(void);

char frame = 0; //boolean signifying when to advance the frame

char pixel = '\333';

char screenWidth = 80;
char screenHeight = 25;

char score1 = 0;
char score2 = 0;

char player1Pos = 10;

char player2Pos = 10;

char ballX = 40;
char ballY = 13;

signed char velX = 0; // positive is right
signed char velY = 0; // positive is down

// char player1Input = '\007'; //using bell as null
// char player2Input = '\007';

int counter = 0;

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
void main(void)
{
    char input;
    char octal = '\333';

    PORT_INIT();                        // Initialize the Crossbar and GPIO
    SYSCLK_INIT();                      // Initialize the oscillator
    UART0_INIT();                       // Initialize UART0
    TIMER_INIT();

    SFRPAGE = UART0_PAGE;               // Direct output to UART0


    nextPoint(); //print board, score and prompt to start

    while(1)
    {
        // input = getCharNoHang();             // TODO: this hangs, it shouldn't
        // if(input == 'w' || input == 's'){
        //     player1Input = input;
        // }
        // if(input == 'o' || input == 'l'){
        //     player2Input = input;
        // }

        //printf("\rcounter: %d... frame: %d", counter, frame);

        if(frame == 1){
            if(goalScored()){
                if(score1 == 10 || score2 == 10){
                    gameOver();
                } else{ 
                    nextPoint();
                }
            }
            else{
                input = getCharNoHang();
                updatePositions(input);
                updateBall();
                frame = 0;
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

    
    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.

}

void TIMER0_ISR (void) __interrupt 1 // Corresponds to timer 0 overflow - 0.1s has elapsed
{
    counter++;
    //3000 is 1fps for debugging
    //30 fps for now (100 counter)
    if(counter >= 100){ // ISR called at 3000HZ / 50 = 60 fps
        frame = 1;
        counter = 0;
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


//------------------------------------------------------------------------------------
// PORT_Init
//------------------------------------------------------------------------------------
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

void advanceBall(){
    //paddle
    //test within one extra Y coordinate in case of a corner hit
    if(ballX + velX < 3 && ballY >= player1Pos-1 && ballY <= player1Pos + 5){ //player 1 hit
        
        if(ballY == player1Pos-1 && velY > 0){ //top corner and ball moving towards paddle (down)
            velX = 2;
            velY = -2;
        }
        else if(ballY == player1Pos){ // top-most block
            velX = 1;
            velY = -2;
        }
        else if(ballY == player1Pos+1){ // top block
            velX = 1;
            velY = -1;
        }
        else if(ballY == player1Pos+2){ // middle block
            velX = 2;
            velY = 0;
        }
        else if(ballY == player1Pos+3){ // bottom block
            velX = 1;
            velY = 1;
        }
        else if(ballY == player1Pos+4){ // bottom-most block
            velX = 1;
            velY = 2;
        }
        else if(ballY == player1Pos+5 && velY < 0){ // bottom corner and ball moving towards paddle (up)
            velX = 2;
            velY = 2;
        }
        else{ //corner, but ball moving away from paddle (miss)
        }
        // Dont conserve horizontal velocity on paddle hit (like is done for walls below)
        // Just change it to the speed depending on the hit 
        // (aka, just use paddle velocity and forget about incident ball velocity)
        // This also works for the miss case, the ball will continue past the paddle
        ballX += velX;
    // normally it would be ballX + velX > 77 (paddle is located @ 78), but the ball is two pixels wide and 
    // ballx represents the left side, so we subtract one here
    } else if(ballX + velX > 76 && ballY >= player2Pos-1 && ballY <= player2Pos + 5){ // player 2 hit
        if(ballY == player2Pos-1 && velY > 0){ //top corner and ball moving towards paddle (down)
            velX = -2;
            velY = -2;
        }
        else if(ballY == player2Pos){ // top-most block\
            velX = -1;
            velY = -2;
        }
        else if(ballY == player2Pos+1){ // top block\
            velX = -1;
            velY = -1;
        }
        else if(ballY == player2Pos+2){ // middle block\
            velX = -2;
            velY = 0;
        }
        else if(ballY == player2Pos+3){ // bottom block\
            velX = -1;
            velY = 1;
        }
        else if(ballY == player2Pos+4){ // bottom-most block\
            velX = -1;
            velY = 2;
        }
        else if(ballY == player2Pos+5 && velY < 0){ // bottom corner and ball moving towards paddle (up)
            velX = -2;
            velY = 2;
        }
        else{ //corner, but ball moving away from paddle (miss)
        }
        // Dont conserve horizontal velocity on paddle hit (like is done for walls below)
        // Just change it to the speed depending on the hit 
        // (aka, just use paddle velocity and forget about incident ball velocity)
        // This also works for the miss case, the ball will continue past the paddle
        ballX += velX;
    } else{ // no collision
        ballX += velX;
    }

    //ceiling and floor (allow for greater than 1 velY)
    if(ballY + velY < 1){ //ceiling collision
        ballY = 1+(1-(ballY+velY)); //update Y position
        velY *= -velY; //reverse direction
    } 
    else if(ballY + velY > 25){ //floor collision
        ballY = 25 - ((ballY+velY)-25); // update Y position
        velY *= -velY; //reverse direction
    } 
    else{ // no collision
        ballY += velY;
    }

}

void updateBall(){
    char str[20];

    //=======ERASE THE LAST BALL=============

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
    //ball is two pixels wide, so test twice
    if(ballX == 40){  // middle divider
        printf("| ");
    } else if(ballX + 1 == 40){ // middle divide
        printf(" |");
    } else if(ballX == 35 && ballY == 2){ // player 1 score
        printf("%d ",score1);
    } else if(ballX + 1 == 35 && ballY == 2){ // player 1 score
        printf(" %d", score1);
    } else if(ballX == 45 && ballY == 2){ // player 2 score
        printf("%d ",score2);
    } else if(ballX + 1 == 45 && ballY == 2){ // player 2 score
        printf(" %d", score2);
    }
    else{ //just empty space
        printf("  ");
    }

    //Move the ball forward 1 frame. Includes collision detection
    advanceBall();

    //===============PRINT THE NEW BALL=================
    tenthsX = '0'+(ballX/10);
    onesX = '0'+(ballX%10);
    
    tenthsY = '0'+(ballY/10);
    onesY = '0'+(ballY%10);

    strcpy(str, "\033[__;__H");

    str[2] = tenthsY;
    str[3] = onesY;
    str[5] = tenthsX;
    str[6] = onesX;

    printf(str);
    printf("%c%c",pixel,pixel);
}

void updatePositions(char input){
	if(input == 'w'){ //w
		player1Pos--;
		if(player1Pos<1){
			player1Pos = 1;
		}
	}

	if(input == 's'){ //s
		player1Pos++;
		if(player1Pos>20){
			player1Pos = 20;
		}
	}

	if(input == 'o'){ //o
		player2Pos--;
		if(player2Pos<1){
			player2Pos = 1;
		}
	}

	if(input == 'l'){ //l
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
    printf("%d",score1);

    // Player 2 score
    printf("\033[2;45H");
    printf("%d",score2);
}

void gameOver(){
    //stop timer
    TR0 = 0;

    printWinner();

    score1 = 0;
    score2 = 0;
    nextPoint();
}

void printWinner(){
    //fireworks and such
    printf("\033[2J");                  // Erase screen & move cursor to home position

    printf("\033[12;28H");
    if(score1 == 10){
        printf("Player 1 is the winner!!");
    } else if(score2 == 10){
        printf("Player 2 is the winner!!");
    }

    printf("\033[20;26H");
    printf("Press any key to play again.");

    getchar(); //hangs on user input

    nextPoint();
}

char goalScored(){
    if(ballX <= 2){ // Player 2 score
        score2++;
        return 1;
    } else if(ballX >= 78){ // Player 1 score
        score1++;
        return 1;
    } else{
        return 0;
    }
}

void nextPoint(){
    //stop timer
    TR0 = 0;

    printBorder();
    updateScore();

    //loser serves (gets first hit)
    if(score1>score2){
        velX = 1;
    } else{ // player 1 serves first
        velX = -1;
    }

    //center cursor for start prompt
    printf("\033[12;27H");
    printf("Press any button to start!");

    getchar();

    //erase prompt and replace middle divider
    printf("\033[12;27H");
    printf("             |            ");

    //clear timer
    TL0 = 0x00;                 // Clear low byte of register T0
    TH0 = 0x00;                 // Clear high byte of register T0 (set auto reload to zero)
    counter = 0;
    frame = 0;


    //start Timer0
    TR0 = 1;
}