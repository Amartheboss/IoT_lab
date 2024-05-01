// play sound after knocks using piezo element

#define LED 4 //led at pin 4
#define buzzer 9 //buzzer at pin 9
#define sensor A0 //sensor at pin A0
int sound=250; //set buzzer sound
void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
void loop() {
  int detect=digitalRead(sensor);//read status of sensor
  //if sensor detcts obstacle
  if(detect==HIGH) {
    digitalWrite(LED,HIGH); //led on
    tone(buzzer,sound); //buzzer sounds
  }
  else {
    digitalWrite(LED,LOW);
    noTone(buzzer);
  }
  delay(300);
}