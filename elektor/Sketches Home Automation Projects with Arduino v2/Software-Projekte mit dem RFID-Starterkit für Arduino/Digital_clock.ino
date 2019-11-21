// Digital_clock.ino
#include <Time.h>
#include <SevenSeg.h>
// segments a b c d e f g
SevenSeg disp (2 ,3 ,4 ,5 ,6 ,7 ,8);
const int numOfDigits=4;
// Arduino pins D10 D11 D12 D13
// digit 4 2 2 1
int digitPins [numOfDigits]={ 13, 12, 11, 10};
void setup()
{ // 20:15:00 am 1. Januar 2017.
setTime(20, 15, 00, 01, 01, 2017);
disp.setCommonCathode();
disp.setDigitPins (numOfDigits, digitPins);
disp.setDPPin(9); // pin for decimal dot
}
void loop()
{ if ((second()%2) == 0) disp.writeClock(hour(), minute(), '.');
if ((second()%2) == 1) disp.writeClock(hour(), minute(), '_');
}