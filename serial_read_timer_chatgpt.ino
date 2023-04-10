const int LED_PIN = 10;

unsigned long start_time = 0;

int timeout = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(timeout);
}

void loop() {
  if (Serial.available() > 0) {
    int input_delay = Serial.parseInt();
    if (input_delay > 0) {
      start_time = millis();
      Serial.println((String) "Start Time : " + start_time);
      turn_on_led(input_delay);
      Serial.println((String) "Stop Time : " + millis());
    }
  }
}

void turn_on_led(int delay_time) {
  unsigned long current_time = millis();
  while (millis() - current_time < delay_time) {
    digitalWrite(LED_PIN, HIGH);
    delay(50);
  }
  digitalWrite(LED_PIN, LOW);
}