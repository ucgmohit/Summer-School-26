#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust if necessary
const int sensorPin = A0;      // Pulse sensor input
const int enableButton = 2;    // Button input for AND gate
const int ledPin = 13;         // LED output via OR gate
const int threshold = 550;     // Threshold for pulse detection

int bpm = 0;
int lastReading = 0;
int currentReading = 0;
unsigned long lastBeatTime = 0;
bool heartbeatDetected = false;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Heartbeat Monitor");
  
  pinMode(sensorPin, INPUT);
  pinMode(enableButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read pulse sensor
  currentReading = analogRead(sensorPin);
  heartbeatDetected = (currentReading > threshold && lastReading <= threshold);

  if (heartbeatDetected) {
    unsigned long currentTime = millis();
    if (lastBeatTime != 0) {
      int beatInterval = currentTime - lastBeatTime;
      bpm = 60000 / beatInterval;
    }
    lastBeatTime = currentTime;
    digitalWrite(ledPin, HIGH); // OR gate LED indication

    // AND gate for LCD display
    if (digitalRead(enableButton) == LOW) {
      lcd.setCursor(0, 1);
      lcd.print("BPM: ");
      lcd.print(bpm);
    }
  } else {
    digitalWrite(ledPin, LOW);
  }

  lastReading = currentReading;
  delay(10); // Smooth signal
}
