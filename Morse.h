#ifndef _Morse_h_
#define _Morse_h_

#include "Arduino.h"

class Morse {
  public:
  Morse(byte pin);
  Morse setup();
  Morse hookCallback(void (*callback)());

  
  void setFrequency(float frequency);
  void setText(String newText);
  
  void displayText();
  
  protected:
  void flash(int on, int off);
  void dot();
  void dash();
  void letter();
  void space();
  void displayChar(char c);
  char* translateChar(char c);
  
  private:
  int T;
  String text;
  byte pin;
  void (*callback)();
};


#endif

