// On LED using letters (R, Y, B, etc)

int redLed = 13;
int yellowLed = 12;
int greenLed = 11;
int userInput;

void setup() {
  Serial.begin(9600);
  Serial.print("Enter an character: ");
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}


void loop() {
  if (Serial.available() > 0) {
    userInput = Serial.read();
    Serial.print("You entered: ");
    Serial.println(userInput);
  }
  if (userInput == 103) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  } else if (userInput == 121) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else if (userInput == 114) {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
  }
}