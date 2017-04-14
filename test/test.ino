/* Blink without Delay

 Turns on and off a light emitting diode (LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 */

// constants used to set a pin number :
const int ledPin = 13;// the number of the LED pin
const int sensor = 8;
// Variables will change :
//int ledState = LOW;             // ledState used to set the LED
int sensorState = LOW;

// unsigned long for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

//this constant will be inserted from serial monitor
int interval;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as input or output:
  pinMode(ledPin, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorState = digitalRead(sensor);
  
 //program start if the sensor will detect something
  if(sensorState == LOW){
  Serial.println("program start");  
  Serial.print("previous millis: ");
  Serial.println(previousMillis);
  // here is where you'd put code that needs to be running all the time.
  unsigned long currentMillis = millis();
  Serial.print("current millis: ");
  Serial.println(currentMillis);
    //waiting for input
    if(Serial.available() > 0){
    interval = Serial.parseInt();
    }//read int or parseFloat for ..float... 
  Serial.print("seteaza intervalul pentru declansare:");
  Serial.println(interval);
  
  if (currentMillis - previousMillis >= interval) {
     digitalWrite(ledPin, HIGH);
     Serial.println("declanseaza");
     Serial.print("current millis: ");
    Serial.println(currentMillis);
     delay(1000); 
     digitalWrite(ledPin, LOW);
    }
     // save the last time you blinked the LED
  previousMillis = currentMillis;
  Serial.print("previous = current millis: ");
  Serial.println(previousMillis);
  }
}

