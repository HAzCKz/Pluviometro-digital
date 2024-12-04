#include <stdio.h>
#define sensor 16
#define led 17

int res = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //int res = 0;

  if (digitalRead(sensor) == HIGH)
  {
    digitalWrite(led, HIGH);
    res = res + 1;
    Serial.println(res);
    delay(167);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println(res);
  }
  
}