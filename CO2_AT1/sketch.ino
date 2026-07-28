#include <Servo.h>

Servo barrier;

const int entrySensor = 2;
const int exitSensor  = 3;

const int warningLED = 10;
const int buzzer = 11;

bool trainPresent = false;

void setup()
{
  pinMode(entrySensor, INPUT_PULLUP);
  pinMode(exitSensor, INPUT_PULLUP);

  pinMode(warningLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  barrier.attach(9);

  barrier.write(0);

  Serial.begin(9600);
  Serial.println("Railway Level Crossing Controller");
}

void loop()
{
  // Train arrives
  if(digitalRead(entrySensor)==LOW && !trainPresent)
  {
    trainPresent = true;

    Serial.println("Train Detected");

    digitalWrite(warningLED,HIGH);
    digitalWrite(buzzer,HIGH);

    delay(1000);

    barrier.write(90);

    Serial.println("Barrier Closed");

    delay(1000);
  }

  // Train leaves
  if(digitalRead(exitSensor)==LOW && trainPresent)
  {
    Serial.println("Train Passed");

    delay(1000);

    barrier.write(0);

    digitalWrite(warningLED,LOW);
    digitalWrite(buzzer,LOW);

    trainPresent=false;

    Serial.println("Barrier Open");
  }
}