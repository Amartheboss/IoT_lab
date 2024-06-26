// Read and display temperature

#define sensorPin A0
void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorVal = analogRead(sensorPin); // reading the tempretre value
  float temperature = sensorVal * 0.48828125; // convert the analog voltage to temperature
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("C");
  delay(1000); // update sensor reading every second
}