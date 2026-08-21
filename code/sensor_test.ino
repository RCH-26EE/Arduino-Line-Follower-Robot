const byte sensorPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  Serial.begin(9600);

  for (byte i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  for (byte i = 0; i < 8; i++) {
    Serial.print(digitalRead(sensorPins[i]));

    if (i < 7) {
      Serial.print(" ");
    }
  }

  Serial.println();
  delay(300);
}
