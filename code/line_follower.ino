// ==========================================
// 8-SENSOR LINE FOLLOWER ROBOT
// Arduino Uno + L298N + 8-Channel IR Array
// ==========================================

// IR sensor pins
const int sensorPins[8] = {
  2, 3, 4, 5, 6, 7, 8, 9
};

// L298N motor driver
const int ENA = 10;
const int IN1 = 12;
const int IN2 = 13;

const int ENB = 11;
const int IN3 = A0;
const int IN4 = A1;

// Motor speed
int baseSpeed = 150;
int turnSpeed = 170;


void setup() {

  for (int i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();
}


void loop() {

  int sensor[8];

  // Read all 8 sensors
  for (int i = 0; i < 8; i++) {
    sensor[i] = digitalRead(sensorPins[i]);
  }


  // ==========================================
  // LINE DETECTION
  // ==========================================

  // Center sensors detect the line
  if (sensor[3] == LOW || sensor[4] == LOW) {

    forward();
  }

  // Line is towards the left
  else if (sensor[0] == LOW ||
           sensor[1] == LOW ||
           sensor[2] == LOW) {

    turnLeft();
  }

  // Line is towards the right
  else if (sensor[5] == LOW ||
           sensor[6] == LOW ||
           sensor[7] == LOW) {

    turnRight();
  }

  // No sensor detects the line
  else {

    stopMotors();
  }
}


// ==========================================
// MOTOR CONTROL
// ==========================================

void forward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}


void turnLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);
}


void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);
}


void stopMotors() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
