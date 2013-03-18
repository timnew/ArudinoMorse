
String readString(char terminator) {
  String result = "";
  char buffer[256];
  
  while(true) {
    byte len = Serial.readBytesUntil(terminator, buffer, 255);
    
    if (len == 0) {
      result += String(buffer);
    }
    else {
      buffer[len] = '\0';
      result += String(buffer);
      break; 
    }
  }
 
  return result;
}

void readFrequency() {
    if(!Serial.find("f:")) {
     Serial.println("Error\n");
     return;
   }
            
   float f = Serial.parseFloat();
   
   if(!Serial.find(";")) {
      Serial.println("Error\n");
      return;
   }
   
   Serial.println("Okay");
   
   setupFrequency(f);  
}

void readText() {
     if(!Serial.find("t:")) {
      Serial.println("Error\n");
     return;
   }
     
   String t = readString(';');
   Serial.println("Okay");
   setupText(t);
}

void readInput(){
   if(!Serial.available())
     return;
   
   switch(Serial.peek()){
     case 'f':
       readFrequency();
       break;       
     case 't':
       readText();
       break;
     default:
       Serial.println("Error\n");
       break;
   }
}
