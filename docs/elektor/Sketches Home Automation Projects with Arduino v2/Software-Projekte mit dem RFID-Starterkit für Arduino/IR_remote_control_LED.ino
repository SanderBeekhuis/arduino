// IR_remote_control_LED.ino
#include <IRremote.h>
const int irReceiverPin = 2; //ir receiver @ pin2
const int ledPin = 13;
IRrecv irrecv(irReceiverPin);
decode_results results;
void setup()
{ pinMode(ledPin,OUTPUT);
Serial.begin(9600);
irrecv.enableIRIn();
}
void loop()
{ if (irrecv.decode(&results))
{ Serial.print("irCode: "); Serial.println(results.value, HEX);
irrecv.resume();
delay(100);
if(results.value == 0x9716BE3F) // key code "1"
{ digitalWrite(ledPin,HIGH);
Serial.println("key code 1 detected");
}
if(results.value == 0xC101E57B) // key code "0"
{ digitalWrite(ledPin,LOW);
Serial.println("key code 0 detected");
}
}
}