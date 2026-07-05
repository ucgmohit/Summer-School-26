# Environmental Monitoring Station (DHT11)

## Project Description
This project reads temperature and humidity using a DHT11 sensor every 2 seconds and displays the data on the Serial Monitor in CSV format. A Red LED turns ON if the temperature is above 35°C or humidity is above 80%. Otherwise, a Green LED remains ON.

## Hardware Required
- Arduino UNO
- DHT11 Sensor
- Red LED
- Green LED
- 2 × 220 Ω Resistors
- Breadboard
- Jumper Wires

## Library Used
- DHT Sensor Library by Adafruit
- Version: 1.4.6
- Adafruit Unified Sensor Library

## CSV Output Format
timestamp,temp_C,temp_F,humidity

Example:
0,29.0,84.2,60.0
2000,29.1,84.4,60.0

## Author
Name: Mohit Kumar
