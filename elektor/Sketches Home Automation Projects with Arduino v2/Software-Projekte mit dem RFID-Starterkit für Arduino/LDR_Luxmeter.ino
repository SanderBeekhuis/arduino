// LDR_Luxmeter.ino
int intensity;
int ADC_0=0;
void setup()
{ Serial.begin(9600);
}
void loop()
{ intensity=analogRead(ADC_0);
Serial.print("Helligkeit: ");
Serial.print(intensity/10.23);
Serial.println(" %");
delay(1000);
}