// Stepper_w_joystic_control.ino
#include <Stepper.h>
const int stepsPerRev = 32;
Stepper myStepper(stepsPerRev, 2, 3, 4, 5);
int sensor;
int motorSpeed;
void setup() {}
void loop()
{ sensor = analogRead(A0);
motorSpeed = map(sensor, 0, 1023, -1000, 1000);
if(motorSpeed > 0)
{ myStepper.setSpeed(motorSpeed);
myStepper.step(1);
}
if(motorSpeed < 0)
{ myStepper.setSpeed(-motorSpeed);
myStepper.step(-1);
}
}