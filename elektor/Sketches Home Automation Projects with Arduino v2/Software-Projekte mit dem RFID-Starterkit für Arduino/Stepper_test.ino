// Stepper_test.ino
#include <Stepper.h>
const int stepsPerRev = 32;
Stepper myStepper(stepsPerRev, 2, 3, 4, 5);
void setup()
{ myStepper.setSpeed(500);
}
void loop()
{ myStepper.step(2048);
delay(500);
myStepper.step(-2048);
delay(500);
}