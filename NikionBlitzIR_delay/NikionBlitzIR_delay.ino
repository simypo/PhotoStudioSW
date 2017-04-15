#define Blitz 9
#define Focus 10
#define Shutter 11
#define ledPin 13// the number of the LED pin
#define sensor 8 //LOW cand trece prin bariera de IR
#define Button 7

long interval = 150;


void setup() {
  // set the digital pin as input or output:
  pinMode(Blitz, OUTPUT);
  pinMode(Focus, OUTPUT);
  pinMode(Shutter, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(Button, INPUT);

}

void loop(){
  if (digitalRead(Button) == LOW)
  {
    digitalWrite(Focus, HIGH);
        if(digitalRead(sensor) == HIGH){  
      delay(interval);
      digitalWrite(Shutter, HIGH);
      delay(55);
      //digitalWrite(ledPin, HIGH);
      digitalWrite(Blitz, HIGH);
      //delay(50);
        }
    }else{
     digitalWrite(Focus, LOW);
      //digitalWrite(ledPin, LOW);
      digitalWrite(Shutter, LOW);
      digitalWrite(Blitz, LOW);
  }
  }
