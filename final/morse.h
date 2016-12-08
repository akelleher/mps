#include <stdio.h>              // Necessary for printf and NULL.
#include <c8051f120.h>          // SFR declarations.
#include <stdlib.h>
#include <string.h>

static const char * __xdata morse[36];

// Needed so that charToMorse()doesn't return pointer to local char
// that is then removed from the stack upon frame exit (causing memory error)
static const char * __xdata slash = "/";

int beatCounter = 1; //tenth second counter

int tenthsCounter = 0;

void MORSE_INIT() ;
char* charToMorse(char c);
char stringToMorse(char * str, char * buff);
char outputMessage(char* str, char * buff);
void outputDit();
void outputDah();
void waitBeats(int beats);
void outputPulse(int length);
char parseLetter(char * buff3);


void MORSE_INIT() {
	morse[0]    = ".-";         // A
	morse[1]    = "-...";       // B
	morse[2]    = "-.-.";       // C
	morse[3]    = "-..";        // D
	morse[4]    = ".";          // E
	morse[5]    = "..-.";       // F
	morse[6]    = "--.";        // G
	morse[7]    = "....";       // H
	morse[8]    = "..";         // I
	morse[9]    = ".---";       // J
	morse[10]   = "-.-";        // K
	morse[11]   = ".-..";       // L
	morse[12]   = "--";         // M
	morse[13]   = "-.";         // N
	morse[14]   = "---";        // O
	morse[15]   = ".--.";       // P
	morse[16]   = "--.-";       // Q
	morse[17]   = ".-.";        // R
	morse[18]   = "...";        // S
	morse[19]   = "-";          // T
	morse[20]   = "..-";        // U
	morse[21]   = "...-";       // V
	morse[22]   = ".--";        // W
	morse[23]   = "-..-";       // X
	morse[24]   = "-.--";       // Y
	morse[25]   = "--..";       // Z
	morse[26]   = "-----";      // 0
	morse[27]   = ".----";      // 1
	morse[28]   = "..---";      // 2
	morse[29]   = "...--";      // 3
	morse[30]   = "....-";      // 4
	morse[31]   = ".....";      // 5
	morse[32]   = "-....";      // 6
	morse[33]   = "--...";      // 7
	morse[34]   = "---..";      // 8
	morse[35]   = "----.";      // 9

	slash = "/";
}

char* charToMorse(char c){
    if(c >= '0' && c <= '9'){
    	//digits start at index 26
    	return morse[(c-'0')+26];
    }
    else if(c >= 'A' && c <= 'Z'){
    	//alphabet starts at index 0
    	return morse[c-'A'];
    }
    else if(c >= 'a' && c <= 'z'){
    	//alphabet starts at index 0
    	return morse[c-'a'];
    }
    else if(c == ' '){
    	return slash; //return a slash for a space (one beat)
    }
    else { // not a proper character
    	return NULL;
    }
}

char parseLetter(char * buff3){
	char i = 0;
	char j = 0;
	char successFlag = 1;
	for(i = 0; i < 36; i++){
		successFlag = 1;

		while(buff3[j]!='\0'){
			if(buff3[j] != morse[i][j]){
				successFlag = 0;
				break;
			}
			j++;
		}

		if(successFlag){
			if(i < 26){ //letter
				return 'A' + i;
			} else{ //number
				return '0' + (i-26);
			}
		}
	}

	return '\0';
}

//returns error code 
char stringToMorse(char * str, char * buff){
    int i = 0;
    int buffIndex = 0;
    int j = 0;
    char * tmp;
	// printf("in string to morse\r\n");
    while(str[i] != '\0'){ //end string character
        tmp = charToMorse(str[i]);
    	// printf("converted %c to %s\r\n", str[i], tmp);
        if(tmp == NULL){
    		printf("return 1\r\n");
        	return 1;
        }
        //append to buffer
        if(i == 0){
        	strcpy(buff, tmp);
        }else{
        	strcat(buff, tmp);
        }
        // printf("current buffer: %s\r\n", buff);
        //add a space (if not last char)
        if(str[i+1] != '\0'){
        	strcat(buff, " ");
    	}

        i++;
    }
    // printf("return 0\r\n");
    return 0;
}


char outputMessage(char* str, char * buff){
	int i = 0;
	char err;
	err = stringToMorse(str, buff);
	if(err){
		printf("ERROR IN OUTPUT MESSAGE\r\n");
		return err;
	}
	
	printf("String to morse success:\r\n");
	printf("%s\r\n",str);
	printf("%s\r\n",buff);

	// printf("Entering while...\r\n");
	while(buff[i] != '\0'){
		// printf("CHAR: [%c]\r\n",buff[i]);
		if(buff[i] == ' '){ //wait 3 beats
			// printf("SPACE\r\n");
			waitBeats(3);
		} 
		else if (buff[i] == '/'){
			// printf("SLASH\r\n");
			waitBeats(1);
		}
		else if (buff[i] == '.'){
			// printf("dit\r\n");
			outputDit();

			if(buff[i+1] == '.' || buff[i+1] == '-'){				
				waitBeats(1);
			}
		}
		else if (buff[i] == '-'){
			// printf("dah\r\n");
			outputDah();
			if(buff[i+1] == '.' || buff[i+1] == '-'){				
				waitBeats(1);
			}
		}

		i++;
	}
	return 0;
}

void outputDit(){
	// printf("in output dit\r\n");
	outputPulse(1); //Dit is 1/6 of beat
}

void outputDah(){
	outputPulse(3);	//Dah is 1/2 of beat
}

//Wait whole number of beats
void waitBeats(int beats){
	int timestamp;
	//INSERT DELAY
	timestamp = tenthsCounter;
	while(tenthsCounter-timestamp < beatCounter*beats);
}

//Output pulse of length cycles to P1.1
void outputPulse(int beats){
	int timestamp;
	char SFRPAGE_SAVE;

	// printf("in output pulse\r\n");	

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    // printf("Saved sfrpage");

    SFRPAGE = CONFIG_PAGE;  //NEED TO CHANGE PAGE FOR P1

    // CANNOT PRINT HERE
    // printf("changed sfrpage");

    P1 |= 0x01; //laser on
    P1 |= 0x08; //buzzer on
	// printf("ON");

	//INSERT DELAY
	timestamp = tenthsCounter;
	while(tenthsCounter-timestamp < beatCounter*beats);

    P1 &= 0xFE; //laser off
    P1 &= 0xF7; //buzzer off
	// printf("OFF");

	SFRPAGE = SFRPAGE_SAVE; //PAGE NOT CHANGING BACK TO ALLOW PRINTS
	// printf("exiting output pulse\r\n");
}
