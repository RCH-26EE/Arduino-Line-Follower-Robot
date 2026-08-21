// L298N Motor Driver Test
// Arduino Uno

const int ENA = 10;
const int IN1 = 12;
const int IN2 = 13;

const int ENB = 11;
const int IN3 = A0;
const int IN4 = A1;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  // Move forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  delay(2000);

  // Stop
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  delay(1000);

  // Move backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  delay(2000);

  // Stop
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  delay(1000);
}
