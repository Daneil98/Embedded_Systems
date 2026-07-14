
int PIR = 2;
int LED = 12;
int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(buzzer, HIGH);
  noTone(buzzer);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = digitalRead(PIR);
  Serial.println(sensorValue);
  
  if (sensorValue == HIGH) {
    digitalWrite(LED, HIGH);
    tone(buzzer, 500, 2000);
  }

  else {
    digitalWrite(LED, LOW);
    noTone(buzzer);
  }
}
