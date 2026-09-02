// Pin Definitions
const int trigPin = 10;
const int echoPin = 9;

long duration;
int distanceCm;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 1. Ensure a clean LOW pulse before triggering
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. Send a 10-microsecond HIGH pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. Read the echo pulse width (time in microseconds)
  duration = pulseIn(echoPin, HIGH);

  // 4. Calculate distance in cm
  // Speed of sound = 0.034 cm/us. Divide by 2 to account for round trip.
  distanceCm = (duration / 2.0) * 0.034;

  // 5. Output to Serial Monitor
  Serial.print("Distance = ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // Brief delay to prevent flooding the serial stream
  delay(100); 
}