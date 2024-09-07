#include <Servo.h>

Servo myservo;

int ledPin7 = 7;
int ledPin8 = 8;
const int soundSensorPin = A2;
const int threshold = 50;





void setup() {
  Serial.begin(9600);
  myservo.attach(3);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(soundSensorPin, INPUT);
}

void loop() {
  int soundSense = analogRead(soundSensorPin);
  Serial.println(soundSense);
  if (soundSense >= threshold) {
    digitalWrite(ledPin7, HIGH);
    delay(1000);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, HIGH);
    delay(1000);
    digitalWrite(ledPin8, LOW);

    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(1000);
  }

  
}
