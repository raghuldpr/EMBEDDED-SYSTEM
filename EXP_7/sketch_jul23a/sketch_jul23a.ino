int number = 0;

void setup()
{
  Serial.begin(9600);   // Initialize serial communication
}

void loop()
{
  Serial.print("Number is ");
  Serial.println(number);  // Print the current number
  delay(500);              // Wait for 500 ms
  number++;                // Increment the number
}