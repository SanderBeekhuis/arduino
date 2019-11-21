// HC595_poti_voltmeter.ino
int CLOCK = 12;
int LATCH = 11;
int DATA = 10;
const int analogInPin = A0;
const int analogOutPin = 9;
int sensorValue = 0, mappedValue = 0, outputValue = 0;
void setup()
{ pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
Serial.begin(9600);
}
void loop()
{ sensorValue = analogRead(analogInPin);
mappedValue = map(sensorValue, 0, 1050, 0, 8);
outputValue = (1 << mappedValue);
Serial.print("sensor = ");
Serial.print(sensorValue);
Serial.print("\t mapped = ");
Serial.print(mappedValue);
Serial.print("\t output = ");
Serial.println(outputValue);
digitalWrite(LATCH, LOW);
shiftOut(DATA, CLOCK, MSBFIRST, outputValue);
digitalWrite(LATCH, HIGH);
delay(100);
}