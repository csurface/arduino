// the setup routine runs once
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Wait for serial port to connect (Needed for native USB port only)
  while (!Serial) {
    ;
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // Print a statement through Serial
  Serial.println("Hello world !");
  // Some delay
  delay(1000);
}
