// DHT11_test.ino
#include <dht.h>
dht DHT;
#define DHT11_PIN 4
void setup()
{ Serial.begin(9600);
// Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}
void loop()
{ DHT.read11(DHT11_PIN);
Serial.print("Humidity: "); Serial.print(DHT.humidity,0); Serial.
println(" %");
Serial.print("Temperature: "); Serial.print(DHT.temperature,0); Serial.
println(" C");
Serial.println();
delay(1000);
}