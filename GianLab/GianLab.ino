void setup() {
  // put your setup code here, to run once:
  int pin1 = 1;
  int pin2 = 2;
  int pin3 = 3;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  delay(1000);
  digitalWrite(pin1, LOW);
  delay(1000);
  digitalWrite(pin2, LOW);
  delay(1000);
  digitalWrite(pin3, LOW);
}
