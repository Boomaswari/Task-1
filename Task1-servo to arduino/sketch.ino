#include <Servo.h>
Servo myServo;
const int servoPin = 9;

void setup() {
 
  myServo.attach(servoPin);
}

void loop() {
 
  myServo.write(0);
  delay(1000);
 
  myServo.write(90);
  delay(1000);
 
  myServo.write(180);
  delay(1000);
 
  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
 
}
