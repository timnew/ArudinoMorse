void setup() {
  Serial.begin(9600);   
  pinMode(ledPin, OUTPUT);  
  pinMode(buttonPin, INPUT);
  
  Serial.println("f:frequency(hz);t:text;");
  setupFrequency(10);
  setupText("SOS");
}

void setupFrequency(float frequency){
  Serial.print("Frequency: ");
  Serial.print(frequency);
  Serial.println(" Hz");
  T = int(1000/frequency);
}

void setupText(String newText) {
  text = newText;
  text.toUpperCase();
}

