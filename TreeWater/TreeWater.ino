const int redPin = 13;
const int bluePin = 12;
const int inputPin = 2;
int state = LOW;

// White led flashes periodically to indicate on.
// Red led turns on to indicate out of water condition.
void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(inputPin, INPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
}

void loop() {
  state = digitalRead(inputPin);
  if (state == LOW) {
    digitalWrite(redPin, LOW);
    Serial.println("Merry Christmas!");
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
  } else {
    digitalWrite(redPin, HIGH);
    timeToWater = true;
    Serial.println("Time to water the tree!");
  }
  delay(5000);
}
