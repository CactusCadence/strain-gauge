#include <Arduino.h>

// put function declarations here:
void myFunction();

void setup() {
  // put your setup code here, to run once:
  myFunction();
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