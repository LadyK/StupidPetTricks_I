
#include<Servo.h>
Servo myservo;
int pos = 0;
int distanceValue = 0;
int pressPin = 10;
int distancePin = 3;
int ledPinOne = 6; //The Eyes of the Pug
int light = 0;
int pressValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(4 ,OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  myservo.attach(3);

}

void loop() {
  distanceValue = analogRead(A0);
  delay(10);//distanceValue read pin is A0
  pressValue = analogRead(A2);
  delay(10);//pressureValue read pin is A2
//  Serial.println(pressValue);
 //  Serial.println(distanceValue);
 
   light = map(distanceValue,0,400,50,255);
   Serial.println(light);  
  if(pressValue > 100){
  analogWrite(6,255); 
   myservo.write(LOW); 
  }
  if(pressValue < 100)
   {
    analogWrite(6,light);
     pos = map(distanceValue,0,400,0,360);
  myservo.write(pos);
  delay(15);
   }
 
  }



