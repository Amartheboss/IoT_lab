// On LED using Potentiometers

// Define the pins for the LED and potentiometers
#define RED_PIN 9
#define YELLOW_PIN 10
#define GREEN_PIN 11
#define RED_POTENTIOMETER A0
#define YELLOW_POTENTIOMETER A1
#define GREEN_POTENTIOMETER A2

void setup() {
  // Set the LED pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  // Read the values from the potentiometers
  int redValue = analogRead(RED_POTENTIOMETER) / 4;
  int yellowValue = analogRead(YELLOW_POTENTIOMETER) / 4;
  int greenValue = analogRead(GREEN_POTENTIOMETER) / 4;

  // Write the values to the LED pins
  analogWrite(RED_PIN, redValue);
  analogWrite(YELLOW_PIN, yellowValue);
  analogWrite(GREEN_PIN, greenValue);
}