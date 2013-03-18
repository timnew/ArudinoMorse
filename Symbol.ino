void flash(int on, int off) {
  if(on > 0) {
    digitalWrite(ledPin, HIGH);
    delay(T * on);
  }
  if(off > 0) {
    digitalWrite(ledPin, LOW);
    delay(T * off);
  }
  
  readInput();
}

void dot(){
  flash(1, 1);
}

void dash(){
  flash(3, 1);
}

void letter() {
  flash(0, 2);
}

void space() {
  flash(0, 4);
}

