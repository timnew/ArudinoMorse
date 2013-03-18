#include "Morse.h"

void Morse::displayText() {
  int length = text.length();

  Serial.println(text);
  
  for(int index = 0 ; index < length; index ++) {
    displayChar(text.charAt(index));
  }
  
  space();  
}

char letters[][26] = {
  ".-", // A
  "-...", // B
  "-.-.", // C
  "-..", // D
  ".", // E  
  "..-.", // F
  "--.", // G
  "....", // H
  "..", // I
  ".---", // J
  "-.-", // K
  ".-..", // L
  "--", // M
  "-.", // N
  "---", // O
  ".--.", // P
  "--.-", // Q
  ".-.", // R
  "...", // S
  "-", // T
  "..-", // U
  "...-", // V
  ".--", // W
  "-..-", // X
  "-.--", // Y
  "--.." // Z
};

char numbers[][10] = {
 "-----", // 0
 ".----", // 1
 "..---", // 2
 "...--", // 3
 "....-", // 4
 ".....", // 5
 "-....", // 6
 "--...", // 7
 "---..", // 8
 "----." // 9 
};

char* Morse::translateChar(char c) {
  if (c == ' ')
    return " ";
  else if (c >= 'A' && c <= 'Z')
    return letters[c-'A'];
  else if (c >= '0' && c <= '9')
    return numbers[c-'0'];
  else
    return "X";
}

void Morse::displayChar(char c) {
  char* toDisplay = translateChar(c);

  for(char* current = toDisplay; *current != '\0'; current++) {
    switch(*current) {
      case ' ':
        space();
        break;
      case '.':
        dot();
        break;
      case '-':
        dash();
        break;
      default:
        Serial.print("Unkown letter: ");
        Serial.println(c, HEX);
        return;
    }  
  }

  letter();
}

