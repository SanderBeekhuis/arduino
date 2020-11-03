// Seven_segment_number_display.ino
#include <SevenSeg.h>
// segments a b c d e f g
SevenSeg disp (2 ,3 ,4 ,5 ,6 ,7 ,8);
const int numOfDigits = 4;
// Arduino pins D10 D11 D12 D13
// digit 4 2 2 1
int digitPins [numOfDigits]={ 13, 12, 11, 10};
char str[4];
void setup ()
{ disp.setCommonCathode();
disp.setDigitPins (numOfDigits, digitPins);
}
void loop ()
{ disp.write("1234");
}