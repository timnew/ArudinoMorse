#include "Morse.h"

Morse morse(3);

void setup() {
  morse.setup();
  morse.hookCallback(&readInput);

}

void loop() {  
  morse.displayText();
}

