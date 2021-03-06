#include <stdio.h>              // Necessary for printf and NULL.
#include <c8051f120.h>          // SFR declarations.
#include <stdlib.h>
#include <string.h>

static const char * __xdata morse[36];

// Needed so that charToMorse()doesn't return pointer to local char
// that is then removed from the stack upon frame exit (causing memory error)
static const char * __xdata slash = "/";

static const char * __xdata space = " ";


char __xdata morseA[] = ".-";         // A
char __xdata morseB[] = "-...";       // B
char __xdata morseC[] = "-.-.";       // C
char __xdata morseD[] = "-..";        // D
char __xdata morseE[] = ".";          // E
char __xdata morseF[] = "..-.";       // F
char __xdata morseG[] = "--.";        // G
char __xdata morseH[] = "....";       // H
char __xdata morseI[] = "..";         // I
char __xdata morseJ[] = ".---";       // J
char __xdata morseK[] = "-.-";        // K
char __xdata morseL[] = ".-..";       // L
char __xdata morseM[] = "--";         // M
char __xdata morseN[] = "-.";         // N
char __xdata morseO[] = "---";        // O
char __xdata morseP[] = ".--.";       // P
char __xdata morseQ[] = "--.-";       // Q
char __xdata morseR[] = ".-.";        // R
char __xdata morseS[] = "...";        // S
char __xdata morseT[] = "-";          // T
char __xdata morseU[] = "..-";        // U
char __xdata morseV[] = "...-";       // V
char __xdata morseW[] = ".--";        // W
char __xdata morseX[] = "-..-";       // X
char __xdata morseY[] = "-.--";       // Y
char __xdata morseZ[] = "--..";       // Z
char __xdata morse0[] = "-----";      // 0
char __xdata morse1[] = ".----";      // 1
char __xdata morse2[] = "..---";      // 2
char __xdata morse3[] = "...--";      // 3
char __xdata morse4[] = "....-";      // 4
char __xdata morse5[] = ".....";      // 5
char __xdata morse6[] = "-....";      // 6
char __xdata morse7[] = "--...";      // 7
char __xdata morse8[] = "---..";      // 8
char __xdata morse9[] = "----.";      // 9

unsigned int __xdata unitTime = 1; // in centiseconds

unsigned int csCounter = 0;


void MORSE_INIT() ;
char* charToMorse(char c);
char stringToMorse(char * str, char * buff);
char outputMessage(char* str, char * buff);
void outputDit();
void outputDah();
void waitBeats(int beats);
void outputPulse(int length);
char parseLetter(char * buff3);


void MORSE_INIT() {	//Done this way due to funky xdata issue
	morse[0]    = morseA;
	morse[1]    = morseB;
	morse[2]    = morseC;
	morse[3]    = morseD;
	morse[4]    = morseE;
	morse[5]    = morseF;
	morse[6]    = morseG;
	morse[7]    = morseH;
	morse[8]    = morseI;
	morse[9]    = morseJ;
	morse[10]   = morseK;
	morse[11]   = morseL;
	morse[12]   = morseM;
	morse[13]   = morseN;
	morse[14]   = morseO;
	morse[15]   = morseP;
	morse[16]   = morseQ;
	morse[17]   = morseR;
	morse[18]   = morseS;
	morse[19]   = morseT;
	morse[20]   = morseU;
	morse[21]   = morseV;
	morse[22]   = morseW;
	morse[23]   = morseX;
	morse[24]   = morseY;
	morse[25]   = morseZ;
	morse[26]   = morse0;
	morse[27]   = morse1;
	morse[28]   = morse2;
	morse[29]   = morse3;
	morse[30]   = morse4;
	morse[31]   = morse5;
	morse[32]   = morse6;
	morse[33]   = morse7;
	morse[34]   = morse8;
	morse[35]   = morse9;

}

char* charToMorse(char c){	//	Convert single ascii charachter to morse representation
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

char parseLetter(char * buff3){	//	parse morse representation into ascii letter
	char i = 0;
	char j = 0;
	char successFlag = 1;

	for(i = 0; i < 36; i++){	//	Iterate through each Morse letter, compare to buff3
		successFlag = 1;
		j = 0;

		if(!strcmp(buff3, morse[i])){	//	Found matching character
			// printf("FOUND A MATCH");
			if(i < 26){ //letter
				printf("%c",'A' + i );
				return 'A' + i;
			} else{ //number
				printf("%c", '0' + (i-26));
				return '0' + (i-26);
			}
		}

	}
	//printf("No return value\r\n");
	return '\0';
}

//returns error code 
char stringToMorse(char * str, char * buff){	//	Uses charToMorse to convert string of ASCII to string of morse
    int i = 0;
    int buffIndex = 0;
    int j = 0;
    char * tmp;

    char tmpSize = 0;

    while(str[i] != '\0'){ //end string character
        tmp = charToMorse(str[i]);
        tmpSize = 0;

        while(tmp[j] != '\0'){	// make sure we have valid char
        	tmpSize++;
        	j++;
        }
        if(tmp == NULL){
    		printf("return 1\r\n");
        	return 1;
        }


        for(j = 0; j < tmpSize; j++){
        	buff[buffIndex + j] = tmp[j];
        }

        buffIndex += tmpSize;

        //add a space (if not last char)
        if(str[i+1] != '\0'){
        	buff[buffIndex] = ' ';
        	buffIndex += 1;
    	}

        i++;
        j=0;
    }
    buff[buffIndex] = '\0';
    return 0;
}


char outputMessage(char* str, char * buff){	//Convvert ascii to morse, display, and output
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

	while(buff[i] != '\0'){
		if(buff[i] == ' '){ //wait 3 beats
			waitBeats(3);
		} 
		else if (buff[i] == '/'){
			waitBeats(1);
		}
		else if (buff[i] == '.'){
			outputDit();

			if(buff[i+1] == '.' || buff[i+1] == '-'){				
				waitBeats(1);
			}
		}
		else if (buff[i] == '-'){
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
	outputPulse(1); //Dit is 1/6 of beat
}

void outputDah(){
	outputPulse(3);	//Dah is 1/2 of beat
}

//Wait whole number of beats
void waitBeats(int beats){
	int timestamp;
	timestamp = csCounter;
	while(csCounter-timestamp < unitTime*beats);
}

//Output pulse of length cycles to P1.1
void outputPulse(int beats){
	int timestamp;
	char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.
    SFRPAGE = CONFIG_PAGE;  //NEED TO CHANGE PAGE FOR P1

    P1 |= 0x01; //laser on
    P1 |= 0x08; //buzzer on

	timestamp = csCounter;
	while(csCounter-timestamp < unitTime*beats);

    P1 &= 0xFE; //laser off
    P1 &= 0xF7; //buzzer off
	// printf("OFF");

	SFRPAGE = SFRPAGE_SAVE; 
}
