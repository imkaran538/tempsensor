int sensorPin = A0;  
int piezoPin = 9;    
int ledPin = 12;
void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
  
}

void loop() {
  int reading = analogRead(sensorPin);
  float voltage = reading * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0; 

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC > 24.0) {   
    tone(piezoPin, 1000);
    digitalWrite(ledPin, HIGH);       
  } else {
    noTone(piezoPin);
    digitalWrite(ledPin, LOW);           
  }

  delay(1000); 
}