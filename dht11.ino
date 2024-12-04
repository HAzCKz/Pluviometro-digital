#include <DHT11.h>

#include <dummy.h>

#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>


/* Arduino example code for DHT11, DHT22/AM2302 
   and DHT21/AM2301 temperature and humidity sensors. 
   More info: www.www.makerguides.com */

#include "Adafruit_Sensor.h"
#include "DHT.h"

// Set DHT pin:
#define DHTPIN 4

// Set DHT type, uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

  // Setup sensor:
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements:
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Lê a umidade em %:
  float h = dht.readHumidity();
  // Lê a temperatura em Celsius:
  float t = dht.readTemperature();
  // Lê a temperatura em Fahrenheit:
  float f = dht.readTemperature(true);

  // Verifica se as variáveis estão sendo computadas:
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Falha na leitura do sensor!");
    return;
  }

  // Computa o índice de calor em Fahrenheit (default):
  float hif = dht.computeHeatIndex(f, h);
  // Computa o índice de calor em Celsius:
  float hic = dht.computeHeatIndex(t, h, false);


  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" \xC2\xB0");
  Serial.print("C | ");
  Serial.print(f);
  Serial.print(" \xC2\xB0");
  Serial.print("F ");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" \xC2\xB0");
  Serial.print("C | ");
  Serial.print(hif);
  Serial.print(" \xC2\xB0");
  Serial.println("F");
}