#include <Arduino.h>
#include <Adafruit_NAU7802.h>

Adafruit_NAU7802 nau;

// put function declarations here:
void myFunction();

void setup() {
  Serial.begin(115200);

  if(!nau.begin()) {
    Serial.println("Failed to find NAU7802");
  }
}

void loop() {
  myFunction();
}

// put function definitions here:
void myFunction() {
  Serial.print("test! ");
  delay(1000);

  return;
}