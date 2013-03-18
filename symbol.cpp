#include "Morse.h"

void Morse::flash(int on, int off) {
  if(on > 0) {
    digitalWrite(pin, HIGH);
    delay(T * on);
  }
  if(off > 0) {
    digitalWrite(pin, LOW);
    delay(T * off);
  }
  
  if(callback) {
    callback();
  }
}

void Morse::dot(){
  flash(1, 1);
}

void Morse::dash(){
  flash(3, 1);
}

void Morse::letter() {
  flash(0, 2);
}

void Morse::space() {
  flash(0, 4);
}

