//-- Filename: LCD.c
//-- LCD Functions Implementation
//-- Updated for SDCC C compiler and C8051F120
//-- RPK Oct 2007
//
// P7 is used for the control signals, P7.2 = E, P7.1 = RW, P7.0 = RS, output only
// P6 is used for data: P6.7 is read to get the status of the LCD 
// P6 must be configured as bidirectional (open-drain) and set to FF (or at least 80) 
// before reading the status of P6.7

#include <LCD.h>
#include <stdio.h>
#include <stdlib.h>

//----------------------------- LCD related Functions --------------------------------
//#pragma OPTIMIZE (7)


//------------------------------------------------------------------------------------
// lcd_init
//------------------------------------------------------------------------------------
//
void lcd_init(void)
{
	char SFRPAGE_SAVE;

	SFRPAGE_SAVE = SFRPAGE;			// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;
	
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~RS_MASK;	// RS = 0
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~RW_MASK;	// RW = 0
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~E_MASK;	//  E = 0
	large_delay(200);				// 16ms delay

	LCD_DAT_PORT = 0x38;			// set 8-bit mode
	small_delay(1);		//RPK
	pulse_E();
	large_delay(50);				// 4.1ms delay	[50]

	LCD_DAT_PORT = 0x38;			// set 8-bit mode
	small_delay(1);		//RPK
	pulse_E();
	large_delay(3);					// 1.5ms delay		[2]

	LCD_DAT_PORT = 0x38;			// set 8-bit mode
	small_delay(1);		//RPK
	pulse_E();
	large_delay(3);					// 1.5ms delay		[2]

	lcd_cmd(0x06);					// curser moves right
	lcd_clear();
	lcd_cmd(0x0E);					// display and curser on

	SFRPAGE = SFRPAGE_SAVE;			// Restore SFR page
}
//#pragma OPTIMIZE (9)


//------------------------------------------------------------------------------------
// lcd_busy_wait
//------------------------------------------------------------------------------------
//
// wait for the busy bit to drop
//
void lcd_busy_wait(void)
{
	char SFRPAGE_SAVE;

	SFRPAGE_SAVE = SFRPAGE;			// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;
	
	LCD_DAT_PORT = 0xFF;			// Set to FF to enable input on P6
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~RS_MASK;	// RS = 0
	LCD_CTRL_PORT = LCD_CTRL_PORT | RW_MASK;	// RW = 1
	small_delay(3);		// [1 was original delay value]
	LCD_CTRL_PORT = LCD_CTRL_PORT | E_MASK;		//  E = 1
	//TB_GREEN_LED = 1;
	do
	{								// wait for busy flag to drop
		small_delay(2);	// [1 was original delay value]
	} while ((LCD_DAT_PORT & 0x80) != 0);
	//TB_GREEN_LED = 0;

	SFRPAGE = SFRPAGE_SAVE;			// Restore SFR page
}


//------------------------------------------------------------------------------------
// lcd_dat (putchar)
//------------------------------------------------------------------------------------
//
// write a character to the LCD screen
//
char lcd_dat(char dat)
//char putchar(char dat)
{
	char SFRPAGE_SAVE;

	SFRPAGE_SAVE = SFRPAGE;			// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;

	lcd_busy_wait();
	LCD_CTRL_PORT = LCD_CTRL_PORT | RS_MASK;	// RS = 1
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~RW_MASK;	// RW = 0
	LCD_DAT_PORT = dat;
	small_delay(1);		//RPK
	pulse_E();

	SFRPAGE = SFRPAGE_SAVE;			// Restore SFR page

	return 1;
}


//------------------------------------------------------------------------------------
// lcd_puts
//------------------------------------------------------------------------------------
//
// write a string to the LCD screen
//
void lcd_puts(char string[])
{
	int i;
	i=0;
	while(string[i])
	{
		// printf("Printing string[%d]: %c\r\n",i,string[i]);
		lcd_dat(string[i]);
		i++;
	}
}


//------------------------------------------------------------------------------------
// lcd_cmd
//------------------------------------------------------------------------------------
//
// write a command to the LCD controller
//
void lcd_cmd(char cmd)
{
	char SFRPAGE_SAVE;

	SFRPAGE_SAVE = SFRPAGE;			// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;

	lcd_busy_wait();
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~RS_MASK;	// RS = 0
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~RW_MASK;	// RW = 0
	LCD_DAT_PORT = cmd;
	small_delay(1);		//RPK
	pulse_E();

	SFRPAGE = SFRPAGE_SAVE;			// Restore SFR page
}


//------------------------------------------------------------------------------------
// lcd_clear
//------------------------------------------------------------------------------------
void lcd_clear(void)
{
	lcd_cmd(0x01);	//-- clear LCD display
	lcd_cmd(0x80);	//-- cursor go to 0x00
}


//------------------------------------------------------------------------------------
// lcd_goto
//------------------------------------------------------------------------------------
void lcd_goto(char addr)
{
	lcd_cmd(addr | 0x80);
}


//------------------------------------------------------------------------------------
// lcd_home
//------------------------------------------------------------------------------------
void lcd_home(void)
{
	lcd_cmd(0x80);	// cursor to 0 (home)
}


//------------------------------------------------------------------------------------
// lcd_cursor
//------------------------------------------------------------------------------------
void lcd_cursor(__bit on)	// 1 displays cursor, 0 hides it
{
	if (on)
		lcd_cmd(0x0E);	
	else
		lcd_cmd(0x0C);
}


//------------------------------------------------------------------------------------
// delay routines
//------------------------------------------------------------------------------------
//
// delay using spin wait
//
void small_delay(char d)
{
	while (d--);
}


void large_delay(char d)
{
	while (d--)
		small_delay(255);
}


void huge_delay(char d)
{
	while (d--)
		large_delay(255);
}