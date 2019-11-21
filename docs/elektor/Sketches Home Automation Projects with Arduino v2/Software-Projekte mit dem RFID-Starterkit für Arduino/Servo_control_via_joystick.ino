// Servo_control_via_joystick.ino
#include <Servo.h>
Servo myservo;
int analogVal;
void setup() {
myservo.attach(9); // servo is connected to Arduino Pin D9
}
void loop() {
analogVal = analogRead(0); // joystick is connected to A0
analogVal = map(analogVal, 0, 1023, 45, 135); // scale servo to 0 and 180
// degrees
myservo.write(analogVal);
delay(10);
}