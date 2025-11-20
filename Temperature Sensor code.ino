const int sensorPin = A0;
const int coolLed = 8;
const int hotLed = 9;
const int buzzer = 10;

float threshold = 35.0; // Temperature threshold in °C

void setup() {
  pinMode(coolLed, OUTPUT);
  pinMode(hotLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100.0;  // For LM35/TMP36

  Serial.print("Temp: ");
  Serial.println(temperature);

  if (temperature > threshold) {
    digitalWrite(hotLed, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(coolLed, LOW);
  } 
  else {
    digitalWrite(coolLed, HIGH);
    digitalWrite(hotLed, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
