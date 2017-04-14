/* Blink without Delay

 Turns on and off a light emitting diode (LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 */

// constants won't change. Used here to set a pin number :
const int ledPin = 13;// the number of the LED pin
const int sensor = 8;
// Variables will change :
//int ledState = LOW;             // ledState used to set the LED
int sensorState = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
//const int val = 0;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorState = digitalRead(sensor);
  //Serial.println(sensorState);
  if(sensorState == LOW){
  Serial.println("program start");  
  // here is where you'd put code that needs to be running all the time.

    //waiting for input
  while (Serial.available() == 0);
  int val = Serial.parseInt(); //read int or parseFloat for ..float...
    
  Serial.print("seteaza intervalul pentru declansare:");
  Serial.println(val);
  unsigned long currentMillis = millis();
  Serial.print("current millis: ");
  Serial.println(currentMillis);
  if (currentMillis - previousMillis >= val) {
     digitalWrite(ledPin, HIGH);
     delay(1000); 
     digitalWrite(ledPin, LOW);
    }
    // set the LED with the ledState of the variable:
    //digitalWrite(ledPin, ledState);
     // save the last time you blinked the LED
    previousMillis = currentMillis;
  Serial.print("previous millis: ");
  Serial.println(previousMillis);
  }
}

