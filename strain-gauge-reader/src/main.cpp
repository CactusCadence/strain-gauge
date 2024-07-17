#include <Arduino.h>
#include <Adafruit_NAU7802.h>

Adafruit_NAU7802 nau;

int analogPin = 0;
int raw = 0;
int Vin = 3.3;
float Vout = 0;
float R1 = 1000; // 100
float R2 = 0;
float buffer = 0;

// put function declarations here:

void setup() {
  Serial.begin(115200);

  if(!nau.begin()) {
    Serial.println("Failed to find NAU7802");
  }
}

void loop() {
  raw = analogRead(analogPin);
  if(raw) {
    buffer = raw*Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    Serial.print("Buffer: ");
    Serial.println(buffer);
    R2 = R1*buffer;
    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("R2: ");
    Serial.println(R2);
    delay(3000);
  }
}

// put function definitions here: