#include <Arduino.h>
#include <Adafruit_NAU7802.h>

Adafruit_NAU7802 nau;

int analogPin = 0;
int raw = 0;
int Vin = 3.3;
float Vout = 0;
float R1 = 1000;
float R2 = 0; // 100

// Declare variables so they can be used in setup and loop
float buffer = 0;
float initRes = 0; 

// Function declarations:
float readResistance();

void setup() {
  Serial.begin(115200);

  if(!nau.begin()) {
    Serial.println("Failed to find NAU7802");
  }

  delay(100); // Short delay for initial voltage spike
  initRes = readResistance();
}

void loop() {
  // float res = readResistance();
  Serial.print("Res: ");
  Serial.println(initRes);
  delay(3000);
}

// Function definitions:

// readResistance reads the raw voltage of the pin and calculates the resistance
// This can easily be changed later to read the resistance with the ADC instead of raw through the M0
float readResistance() {
  raw = analogRead(analogPin);
  if(raw) {
    buffer = raw*Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2 = R1*buffer;
    return R2;
  }
  // If no raw, return -1
  return -1;
}