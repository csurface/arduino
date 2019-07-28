
byte b;
byte buf[256];
byte response[256];
int index = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    b = Serial.read();
    buf[index] = b;
    index++;      
  } else if (index == 4 && buf[0] == 0x01 && buf[1] == 0x41) {
    // SingleRecordSize request - respond with 25
    response[0] = 0x01;
    response[1] = 0x41;
    response[2] = 0x02;
    response[3] = 0x19;
    response[4] = 0x00;
    response[5] = 0xa7;
    response[6] = 0xac;
    Serial.write(response, 7);
    index = 0;
    digitalWrite(LED_BUILTIN, LOW);
  }
}
