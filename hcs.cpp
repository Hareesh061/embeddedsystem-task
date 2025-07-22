#include <DHT.h>


#define DHTPIN 2
#define DHTTYPE DHT22
#define HEATER_PIN 3
#define LED_PIN 4
#define BUZZER_PIN 5


DHT dht(DHTPIN, DHTTYPE);


float targetTemp = 30.0;
float overheatTemp = 80.0;


enum State { IDLE, HEATING, STABILIZING, TARGET_REACHED, OVERHEAT };
State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(HEATER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Heater Control System Started");
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  
  if (temp >= overheatTemp) {
    currentState = OVERHEAT;
  } else if (temp >= targetTemp - 0.5 && temp <= targetTemp + 0.5) {
    currentState = STABILIZING;
  } else if (temp > targetTemp + 0.5 && temp < overheatTemp) {
    currentState = TARGET_REACHED;
  } else if (temp < targetTemp - 1.0) {
    currentState = HEATING;
  } else {
    currentState = IDLE;
  }


  switch (currentState) {
    case HEATING:
      digitalWrite(HEATER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case STABILIZING:
    case TARGET_REACHED:
      digitalWrite(HEATER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case OVERHEAT:
      digitalWrite(HEATER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);
      break;

    case IDLE:
      digitalWrite(HEATER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      break;
  }

 
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | State: ");
  printState(currentState);

  delay(2000);  
}


void printState(State state) {
  switch (state) {
    case IDLE: Serial.println("IDLE"); break;
    case HEATING: Serial.println("HEATING"); break;
    case STABILIZING: Serial.println("STABILIZING"); break;
    case TARGET_REACHED: Serial.println("TARGET_REACHED"); break;
    case OVERHEAT: Serial.println("OVERHEAT"); break;
  }
}
