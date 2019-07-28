byte b;
byte buf[256];
int index = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}

void loop() {
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  
  if (Serial.available() > 0) {
    b = Serial.read();
    //Serial.print("2017-12-12T12:30:00Z ignored 1.0 unit 2.0 unit 3.0 unit 4.0 unit 5.0 unit\n");
    //if (char(b) == 'Z' || b == 0x0D || b == 0x0A) {
    //if (char(b) == 'D') {
    if (char(b) == '\r') {
      index = 0;
      Serial.print("2017-12-12T12:30:00Z ignored 1.0 unit 2.0 unit 3.0 unit 4.0 unit 5.0 unit\n");
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(1000);
    } else {
      buf[index] = b;
      index++;      
    }
  }
}

