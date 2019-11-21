// Sound_sensor_analog.ino
const int analogInPin = A0;
int sensorValue = 0;
void setup()
{ Serial.begin(115200);
}
void loop()
{ sensorValue = analogRead(analogInPin);
Serial.println(sensorValue);
}