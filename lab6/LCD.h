//-- Filename: LCD.h
//-- Header File for LCD display routines in LCD.c
//-- Updated for SDCC C compiler and C8051F120
//-- RPK Oct 2007

#include <C8051F120.h>

//---------------------------------------------------------------------------
// Global Defines
//---------------------------------------------------------------------------

#define LCD_DAT_PORT  P6		// LCD is in 8 bit mode
#define LCD_CTRL_PORT P7		// 3 control pins on P7
#define RS_MASK       0x01		// for assessing LCD_CTRL_PORT
#define RW_MASK       0x02
#define E_MASK        0x04

//---------------------------------------------------------------------------
// Global MACROS
//---------------------------------------------------------------------------
// original delays [1]
#define pulse_E();\
	small_delay(5);\
	LCD_CTRL_PORT = LCD_CTRL_PORT | E_MASK;\
	small_delay(5);\
	LCD_CTRL_PORT = LCD_CTRL_PORT & ~E_MASK;\

//-- function prototypes ----------------------------------------------------

void lcd_init		(void);		// initialize the LCD to 8 bit mode
void lcd_busy_wait	(void);		// wait until the LCD is no longer busy
char lcd_dat		(char c);	// write data to the LCD controller
//char putchar		(char c);	// replaces standard function and uses LCD
void lcd_puts		(char string[]);// send string to LCD at current cursor location
void lcd_cmd		(char cmd);	// write a command to the LCD controller
void lcd_clear		(void);		// clear display
void lcd_goto		(char addr);// move to address addr
void lcd_home		(void);		// home cursor
//void lcd_move_cursor(char dist);// moves cursor forward or back by dist
void lcd_cursor		(__bit on);	// 1 displays cursor, 0 hides it
void small_delay    (char d);	// 8 bit,  about 0.34us per count @22.1MHz
void large_delay    (char d);	// 16 bit, about 82us   per count @22.1MHz
void huge_delay     (char d);	// 24 bit, about 22ms   per count @22.1MHz

//---------------------------------------------------------------------------