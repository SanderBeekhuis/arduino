// SOS.ino
int ledPin = 13; // LED in series with 1k resistor on pin 12
int i; // declare variable i
void setup()
{ pinMode(ledPin, OUTPUT);
}
void loop()
{ for (i=1; i <= 3; i++)
{ digitalWrite(ledPin, HIGH);
delay(500);
digitalWrite(ledPin, LOW);
delay(500);
}
delay(1000);
for (i=1; i <= 3; i++)
{ digitalWrite(ledPin, HIGH);
delay(1500);
digitalWrite(ledPin, LOW);
delay(1500);
}
delay(1000);
for (i=1; i <= 3; i++)
{ digitalWrite(ledPin, HIGH);
delay(500);
digitalWrite(ledPin, LOW);
delay(500);
}
delay(3000);
}