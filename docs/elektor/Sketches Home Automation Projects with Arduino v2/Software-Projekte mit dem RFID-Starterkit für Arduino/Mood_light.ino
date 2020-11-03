// Mood_light.ino
int ledRed = 6;
int ledGreen = 5;
int ledBlue = 3;
int colorWidth = 1000;
void setup()
{ }
void loop()
{ for(int fadeValue = 0 ; fadeValue <= 255; fadeValue ++)
{
analogWrite(ledRed, 255*exp(-((fadeValue-64)*(fadeValue-64))/
colorWidth));
analogWrite(ledGreen, 100*exp(-((fadeValue-128)*(fadeValue-128))/
colorWidth));
analogWrite(ledBlue, 200*exp(-((fadeValue-193)*(fadeValue-193))/
colorWidth));
delay(2);
}
}