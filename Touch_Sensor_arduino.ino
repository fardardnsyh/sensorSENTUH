
#define TouchSensor 6 // Pin Di gunakan untuk capactitive touch sensor

#define RELAY_ON 0
#define RELAY_OFF 1
#define RELAY_1  12   // pin yang digunakan yaitu pin 12

boolean currentState = LOW;
boolean lastState = LOW;
boolean RelayState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, RELAY_OFF);
  pinMode(TouchSensor, INPUT);
}

void loop() {
  currentState = digitalRead(TouchSensor);
  if (currentState == HIGH && lastState == LOW) {
    Serial.println("pressed");
    delay(1);

    if (RelayState == HIGH) {
      digitalWrite(RELAY_1, RELAY_OFF);
      RelayState = LOW;
    } else {
      digitalWrite(RELAY_1, RELAY_ON);
      RelayState = HIGH;
    }
  }
  lastState = currentState;
}
