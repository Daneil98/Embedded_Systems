#include <DHT.h>

// constants
#define DHTPIN 4            // Temp sensor Pin
#define DHTTYPE DHT22       // DHT 22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT Sensor

int fan = 13;               // Setting Fan Pin
float sensorValue;
float threshold = 37.0;


void setup() {
  // put your setup code here, to run once:
  pinMode(fan, OUTPUT);
  pinMode(DHTPIN, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorValue = dht.readTemperature();
  Serial.println("Temp. Value");
  Serial.println(sensorValue);
  Serial.println(" *C ");

  if (sensorValue > threshold) {
    digitalWrite(fan, HIGH);
    Serial.println("Fan Turned On");
  }
  else{
    digitalWrite(fan, LOW);
    Serial.println("Fan Turned Off");
  }

}
