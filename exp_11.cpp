// Read and display min and max temperature

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float maxTemp = -273.15;  // Initialize to absolute zero
float minTemp = 1000.0;   // Initialize to a very high value

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float temperatureC = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperatureC) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Convert Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Update maximum and minimum temperatures
  maxTemp = max(maxTemp, temperatureC);
  minTemp = min(minTemp, temperatureC);

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C, ");
  Serial.print(temperatureF);
  Serial.print(" °F | Humidity: ");
  Serial.print(humidity);
  Serial.print(" % | Max: ");
  Serial.print(maxTemp);
  Serial.print(" °C | Min: ");
  Serial.print(minTemp);
  Serial.println(" °C");
}

/*
    If ^ not working then try v

    Because ^ needs DHT library :(
*/

#define sensorPin A0 // Define the analog pin for temperature sensor
float maxTemp = -1000.0; // Initialize with a very low value
float minTemp = 1000.0; // Initialize with a very high value

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorVal = analogRead(sensorPin); // Read the analog value from the sensor
  float voltage = sensorVal * 0.0048828125; // Convert the analog reading to voltage (5V -> 1023)
  float temperatureC = (voltage - 0.5) * 100; // Convert the voltage to temperature in Celsius (10mV per degree Celsius)
  float temperatureF = temperatureC * 9.0 / 5.0 + 32.0; // Convert Celsius to Fahrenheit

  // Update maximum and minimum temperatures
  if (temperatureC > maxTemp) { // Check if the current temperature is higher than the recorded maximum
    maxTemp = temperatureC; // Update the maximum temperature
  }
  if (temperatureC < minTemp) { // Check if the current temperature is lower than the recorded minimum
    minTemp = temperatureC; // Update the minimum temperature
  }

  // Print current temperature in Fahrenheit
  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.println("F");

  // Print maximum temperature in Celsius and Fahrenheit
  Serial.print("Max Temperature: ");
  Serial.print(maxTemp * 9.0 / 5.0 + 32.0);
  Serial.println("F");

  // Print minimum temperature in Celsius and Fahrenheit
  Serial.print("Min Temperature: ");
  Serial.print(minTemp * 9.0 / 5.0 + 32.0);
  Serial.println("F");

  delay(1000); // Delay for 1 second before next sensor reading
}