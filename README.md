# 04_10

## 1. Chat GPT 코드 개선

![Image1](/image/Chat1.PNG)

![Image2](/image/Chat2.PNG)

![Image3](/image/Chat3.PNG)

## 3. Blink Without Delay

```
const int ledPin = 10;

int ledState = LOW;

unsigned long previousMillis = 0;

const long interval = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if ((currentMillis - previousMillis) == interval) {
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);
  }
}
```
위는 Examples -> Digital -> BlinkWithoutDelay 코드입니다.
```
if ((currentMillis - previousMillis) >= interval)
```
위 부분이 헷갈렸으나
```
if ((currentMillis - previousMillis) == interval)
```
이 코드로 수정해보니 같은 역할을 한다는 것을 파악할 수 있었고, 이를 통해 훨씬 이해가 쉬워졌습니다.
