#include <Servo.h>
Servo myservo; // create servo object to control a servo
Servo myservo2;
Servo myservo3;
int potpin = 0; // analog pin used to connect the potentiometer
int val; // variable to read the value from the analog pin
int potpin2 = 1;
int val2;
const int buttonPin= 2 ;
const int ledPin = 13;
int buttonState = 0;
int pos = 0;
int pos1 =200;
void setup()
{
 myservo.attach(9); // attaches the servo on pin 9 to the servo object
 myservo2.attach(10);
 myservo3.attach(11);
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin,INPUT);
 Serial.begin(9600);
}
void loop()
{
 val = analogRead(potpin);   // reads the value of the
 val2 = analogRead(potpin2);
          // potentiometer (value between
          // 0 and 1023)
 val = map(val, 0, 1023, 0, 179);  // scale it to use it with
 val2 = map(val2, 0, 1023, 0, 179);
          // the servo (value between 0 and
          // 180)
 myservo.write(val);     // sets the servo position according
 myservo2.write(val2);
          // to the scaled value
 delay(15);       // waits for the servo to get there
 int buttonState = digitalRead(buttonPin);
 Serial.println(buttonState);
 delay(1);
 digitalRead(buttonPin);
  if (buttonState == HIGH)
    {
      digitalWrite(ledPin, HIGH);
      myservo3.write(pos);
      delay(10);
    }
  else
    {
      digitalWrite(ledPin, LOW);
      myservo3.write(pos1);
      delay(15);
    }
    
}
