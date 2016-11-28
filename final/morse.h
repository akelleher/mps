const char * morse[36]; 
static char __xdata buff2[2048];

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
    	return '/'; //return a slash for a space (one beat)
    }
    else { // not a proper character
    	return NULL;
    }
}

//returns error code 
char stringToMorse(char * str, char * buff){
    int i = 0;
    int buffIndex = 0;
    int j = 0;
    char * tmp;
    while(str[i] != '\0'){ //end string character
        tmp = charToMorse(str[i]);
        if(tmp == NULL){
        	return 1;
        }
        //append to buffer
        while(tmp[j] != '\0'){
        	buff[buffIndex] = tmp[j];
        	buffIndex++;
        	j++;
        }
        //add a space (if not last char)
        if(str[i+1] != '\0'){
	        buff[buffIndex] = ' ';
	        buffIndex++;
    	}

        i++;
    }
    return 0;
}
