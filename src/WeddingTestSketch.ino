
int lockControl = 9;
int hallSignalPin = A0; 
int hallLEDPin = 8;
int value = 0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Setting Up");
  
  pinMode(hallSignalPin, INPUT);
  pinMode(hallLEDPin, OUTPUT);
  pinMode(lockControl, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(hallSignalPin);
  // analogWrite(lockControl, 255);

  if(value < 200)
  {
    Serial.println("DETECTION");  
    analogWrite(hallLEDPin, 255);
    analogWrite(lockControl, 255);
  }
  else
  {
    // Serial.print("Reading value ");
    //Serial.println(value);
    analogWrite(hallLEDPin, 0);
    analogWrite(lockControl, 0);
  }
  
  delay(400);
}
