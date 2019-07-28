#include <Wire.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 cap = Adafruit_MPR121();

void setup() {
  Serial.begin(9600);
  cap.begin(0x5A);
  pinMode(LED_BUILTIN, OUTPUT);
}

/*
 * 0001
 * 0010
 * 0100
 * 1000
 * 
 * 0001 == 0x01
 * 0010 == 0x02
 * 0011 == 0x03
 * 1111 == 0x0F
 */
void loop() {
  //Serial.println(cap.touched());
  uint16_t val = cap.touched();
  if (val != 0) {
    String label = "";
    if (val & 0x01) {
      label += "One ";
    }
    if (val & 0x02) {
      label += "Two ";
    }
    if (val & 0x800) {
      label += "Potato ";
    }
    Serial.println("Daddy stop touching me: " + String(val) + " " + label);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
