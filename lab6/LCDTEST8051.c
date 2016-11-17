// Filename: LCDTEST8051.c
// Basic test program for the Hitachi HD 44780
// interfaced to the C8951F120
//-- Updated for SDCC C compiler and C8051F120
//-- RPK Oct 2007
//
// An extra 10k pull-up resistor may be needed on the E control line P7.2
// to the +3.3V supply on P8051F120 board if P7 is configured as open-drain.

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <LCD.c>

//--------------------------------------------------------------------------
// Function Prototypes
//--------------------------------------------------------------------------
void main(void);
void SYSCLK_INIT(void);

//--------------------------------------------------------------------------
// MAIN Routine
//--------------------------------------------------------------------------
void main()
{
	unsigned int i, j;
	char buffer[]="Hello.";

	WDTCN = 0xDE;		// Disable the watchdog timer
	WDTCN = 0xAD;		// note: = "DEAD"!
	
	SYSCLK_INIT();		// Initialize the oscillator

	lcd_init();			// initialize the LCD screen
	lcd_cmd(0x3F);		// set display to 2 lines 5x8
						// (0x30=1 line 5x8, 0x34=1 line 5x10)
	lcd_cmd(0x0C);		// turn on display and cursor
	lcd_cmd(0x01);		// clear display
	
	lcd_goto(0);		// set cursor address to 0
	lcd_dat('G');		// write "Good Morning    "
	lcd_dat('o');		//       "Dave            "
	lcd_dat('o');
	lcd_dat('d');
	lcd_dat(' ');
	lcd_dat('M');
	lcd_dat('o');
	lcd_dat('r');
	lcd_dat('n');
	lcd_dat('i');
	lcd_dat('n');
	lcd_dat('g');
	lcd_dat(',');

	lcd_goto(0x40);		// set cursor address to 0x40=64
	lcd_dat('D');
	lcd_dat('a');
	lcd_dat('v');
	lcd_dat('e'); 
	lcd_dat('.'); 
	
	for(i=0; i<200; i++)// long pause for display
		for(j=0; j<50000; j++);

	lcd_cmd(0x08);		// turn off display

	for(i=0; i<40; i++)	// 1 sec. pause for display
		for(j=0; j<50000; j++);
	
	lcd_cmd(0x0C);		// turn on display and cursor

	for(i=0; i<40; i++)	// 1 sec. pause for display 
		for(j=0; j<50000; j++);
	
	lcd_goto(0xCA);		// set cursor address to 74 (=0x4A)
	
//	lcd_puts(&buffer);	// write buffer to screen-2008 SDCC gives error
	lcd_puts(buffer);	// write buffer to screen

	for(i=0; i<200; i++)// long pause for display 
		for(j=0; j<50000; j++);
	
	lcd_goto(0x10);		// go to address 16 (=0x10)
	lcd_dat(0x41);		// write ABCDE
	lcd_dat(0x42);
	lcd_dat(0x43);
	lcd_dat(0x44);	
	lcd_dat(0x45);
	
	lcd_cmd(0x18);		// shift display left 5 times
	for(i=0; i<15; i++)	// brief pause for display
		for(j=0; j<50000; j++);
	lcd_cmd(0x18);
	for(i=0; i<15; i++)	// brief pause for display
		for(j=0; j<50000; j++);
	lcd_cmd(0x18);
	for(i=0; i<15; i++)	// brief pause for display
		for(j=0; j<50000; j++);
	lcd_cmd(0x18);
	for(i=0; i<15; i++)	// brief pause for display
		for(j=0; j<50000; j++);
	lcd_cmd(0x18);

	for(i=0; i<200; i++)// long pause for display 
		for(j=0; j<50000; j++);
	
	lcd_cmd(0x01);		// clear display

}

//------------------------------------------------------------------------------------
// SYSCLK_Init
//------------------------------------------------------------------------------------
//
// Initialize the system clock to use a 22.11845MHz crystal as its clock source
//
void SYSCLK_INIT(void)
{
	int i;
	char SFRPAGE_SAVE;

	SFRPAGE_SAVE = SFRPAGE;			// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;

	OSCXCN    = 0x67;
	for (i = 0; i < 3000; i++);		// Wait 1ms for initialization
	while (!(OSCXCN & 0x80));
	CLKSEL    = 0x01;

	XBR0=0x04;
	XBR1=0x80;
	XBR2=0x40;						// Enable Crossbar with Weak Pullups

	P7MDOUT=0x07;					// Set E, RW, RS controls to push-pull
	P6MDOUT=0x00;					// P6 must be open-drain to be bidirectional:
									// used for both read & write operations

	SFRPAGE = SFRPAGE_SAVE;			// Restore SFR page
}