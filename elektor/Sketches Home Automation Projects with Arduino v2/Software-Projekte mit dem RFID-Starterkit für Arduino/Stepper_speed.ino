// Stepper_speed.ino
#include <Stepper.h>
const int stepsPerRev = 32;
Stepper myStepper(stepsPerRev, 2, 3, 4, 5);
int motorSpeed;
void setup() {}
void loop()
{ motorSpeed = 1000; // Range: 1...1000 - slow...fast
myStepper.setSpeed(motorSpeed);
myStepper.step(2048);
delay(500);
motorSpeed = 300; // Range: 1...1000 - slow...fast
myStepper.setSpeed(motorSpeed);
myStepper.step(2048);
delay(500);
motorSpeed = 10; // Range: 1...1000 - slow...fast
myStepper.setSpeed(motorSpeed);
myStepper.step(30);
delay(500);
motorSpeed = 1; // Range: 1...1000 - slow...fast
myStepper.setSpeed(motorSpeed);
myStepper.step(10);
delay(500);
}