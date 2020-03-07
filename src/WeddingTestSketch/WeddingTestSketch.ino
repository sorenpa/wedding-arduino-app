
int lockControl = 3;
int hallSignalPin1 = A0;
int hallSignalPin2 = A1;
int hallSignalPin3 = A2;
int hallSignalPin4 = A3;
int hallSignalPin5 = A4;
int hallSignalPin6 = A5; 
int hallLEDPin1 = 10;
int hallLEDPin2 = 9;
int hallLEDPin3 = 8;
int hallLEDPin4 = 7;
int hallLEDPin5 = 6;
int hallLEDPin6 = 5;
int hallReadValue1 = 0;
int hallReadValue2 = 0;
int hallReadValue3 = 0;
int hallReadValue4 = 0;
int hallReadValue5 = 0;
int hallReadValue6 = 0;
bool hallDetected1 = false;
bool hallDetected2 = false;
bool hallDetected3 = false;
bool hallDetected4 = false;
bool hallDetected5 = false;
bool hallDetected6 = false;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Setting Up");
  
  pinMode(hallSignalPin1, INPUT);
  pinMode(hallSignalPin2, INPUT);
  pinMode(hallSignalPin3, INPUT);
  pinMode(hallSignalPin4, INPUT);
  pinMode(hallSignalPin5, INPUT);
  pinMode(hallSignalPin6, INPUT);
  pinMode(hallLEDPin1, OUTPUT);
  pinMode(hallLEDPin2, OUTPUT);
  pinMode(hallLEDPin3, OUTPUT);
  pinMode(hallLEDPin4, OUTPUT);
  pinMode(hallLEDPin5, OUTPUT);
  pinMode(hallLEDPin6, OUTPUT);
  pinMode(lockControl, OUTPUT);
  
}

void loop() {
  // Read all hall sensors
  hallReadValue1 = analogRead(hallSignalPin1);
  hallReadValue2 = analogRead(hallSignalPin2);
  hallReadValue3 = analogRead(hallSignalPin3);
  hallReadValue4 = analogRead(hallSignalPin4);
  hallReadValue5 = analogRead(hallSignalPin5);
  hallReadValue6 = analogRead(hallSignalPin6);

  // HALL SENSOR 1
  Serial.println("################################");  
  if(hallReadValue1 < 200)
  {
    Serial.println("HALL DETECTION 1");  
    analogWrite(hallLEDPin1, 255);
    hallDetected1 = true;
  }
  else
  {
    Serial.print("Hall 1 Reading: ");
    Serial.println(hallReadValue1);
    analogWrite(hallLEDPin1, 0);
    hallDetected1 = false;
  }

  // HALL SENSOR 2
  if(hallReadValue2 < 200)
  {
    Serial.println("HALL DETECTION 2");  
    analogWrite(hallLEDPin2, 255);
    hallDetected2 = true;
  }
  else
  {
    Serial.print("Hall 2 Reading: ");
    Serial.println(hallReadValue2);
    analogWrite(hallLEDPin2, 0);
    hallDetected2 = false;
  }

  // HALL SENSOR 3
  if(hallReadValue3 < 200)
  {
    Serial.println("HALL DETECTION 3");  
    analogWrite(hallLEDPin3, 255);
    hallDetected3 = true;
  }
  else
  {
    Serial.print("Hall 3 Reading: ");
    Serial.println(hallReadValue3);
    analogWrite(hallLEDPin3, 0);
    hallDetected3 = true;
  }

  // HALL SENSOR 4
  if(hallReadValue4 < 200)
  {
    Serial.println("HALL DETECTION 4");  
    analogWrite(hallLEDPin4, 255);
    hallDetected4 = true;
  }
  else
  {
    Serial.print("Hall 4 Reading: ");
    Serial.println(hallReadValue4);
    analogWrite(hallLEDPin4, 0);
    hallDetected4 = true;
  }

  // HALL SENSOR 5
  if(hallReadValue5 < 200)
  {
    Serial.println("HALL DETECTION 5");  
    analogWrite(hallLEDPin5, 255);
    hallDetected5 = true;
  }
  else
  {
    Serial.print("Hall 5 Reading: ");
    Serial.println(hallReadValue5);
    analogWrite(hallLEDPin5, 0);
    hallDetected5 = true;
  }

  // HALL SENSOR 6
  if(hallReadValue6 < 200)
  {
    Serial.println("HALL DETECTION 6");  
    analogWrite(hallLEDPin6, 255);
    hallDetected6 = true;
  }
  else
  {
    Serial.print("Hall 6 Reading: ");
    Serial.println(hallReadValue6);
    analogWrite(hallLEDPin6, 0);
    hallDetected6 = true;
  }

  if(
      hallDetected1 == true &&
      hallDetected2 == true &&
      hallDetected3 == true &&
      hallDetected4 == true &&
      hallDetected5 == true &&
      hallDetected6 == true
    )
  {
    Serial.println("< < < UNLOCK! > > >");
    analogWrite(lockControl, 255);  
  }
  else
  {
    Serial.println("> > > LOCK! < < <");
    analogWrite(lockControl, 0);
  }

  Serial.println("################################");  
  Serial.println();
  
  delay(1000);
}
