/* 
 14.04.2017
 Blitz Pin 9 Output
 Focus Pin 10 Output
 Shutter Pin 11 Output
 IR sensor Pin 8 Input
 Button Pin 7 Input

 */

// constants used to set a pin number :
const int Blitz = 9;
const int Focus = 10;
const int Shutter = 11;
const int ledPin = 13;// the number of the LED pin
const int sensor = 8; //LOW cand trece prin bariera de IR
const int Button = 7;

int sensorState = HIGH;
int ButtonState = LOW;
int FocusState = LOW;
int ShutterState = LOW;

unsigned long previousMillis = 0; 
int interval;

void setup() {
  // set the digital pin as input or output:
  pinMode(Blitz, OUTPUT);
  pinMode(Focus, OUTPUT);
  pinMode(Shutter, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(Button, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorState = digitalRead(sensor);
  ButtonState = digitalRead(Button);
  
  //first press the butten to prepare the focus on camera
  if(ButtonState == HIGH){
  //digitalWrite(Focus, HIGH);
  FocusState == HIGH;
  Serial.println("Button Focus pornit");
    //program start if the sensor will detect something
    if(sensorState == LOW){
    Serial.println("Bariera de IR pornita");
    unsigned long currentMillis = millis();
    //waiting for time input
    if(Serial.available() > 0){
    interval = Serial.parseInt();
    Serial.print("seteaza intervalul pentru declansare:");
    Serial.println(interval);
    }//read int or parseFloat for ..float... 
  
  if (currentMillis - previousMillis >= interval) {
     //digitalWrite(Shutter, HIGH);
     ShutterState == HIGH;
     Serial.println("declanseaza");
     delay(1000); 
     //digitalWrite(Shutter, LOW);
     ShutterState == LOW;
    }
  // save the last time you blinked the LED
  previousMillis = currentMillis;
  }
}else{
  //digitalWrite(Focus, LOW);
   FocusState == LOW;
  Serial.println("Focus oprit");
}
Serial.print("ShutterState: ");
Serial.println(ShutterState);
Serial.print("sensorState: ");
Serial.println(sensorState);
}
