#include "Morse.h"

Morse::Morse(byte ledPin) {
  pin = ledPin;  
  pinMode(pin, OUTPUT);    
  
  setFrequency(10);
  setText("SOS");
}

Morse Morse::hookCallback(void (*cb)()) {
  callback = cb;
}

Morse Morse::setup() {
  Serial.begin(9600); 
  Serial.println("f:frequency(hz); t:text;");    
}

void Morse::setFrequency(float frequency){
  Serial.print("Frequency: ");
  Serial.print(frequency);
  Serial.println(" Hz");

  T = int(1000/frequency);
}

void Morse::setText(String newText) {
  text = newText;
  text.toUpperCase();
  Serial.print("Text: ");
  Serial.println(text);
}


