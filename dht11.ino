#include <DHT.h>
#include <stdio.h>

#define DHTPIN A14 // A14 = D13(no esp32)
#define DHTYPE DHT11

DHT dht(DHTPIN, DHTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if(isnan(temp) || isnan(hum))
  {
    Serial.println("Falha na leitura do sensor!");
  }
  else
  {
    Serial.print("Temperatura: ");
    Serial.println(temp);
    Serial.print("Umidade: ");
    Serial.println(hum);
    //delay(2000);
  }
}
