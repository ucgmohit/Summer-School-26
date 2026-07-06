# Smart Home Air Quality Monitor

## Project Description
This project is a Smart Home Air Quality Monitoring System developed using Arduino UNO in Tinkercad. It continuously monitors air quality using a Gas Sensor and room temperature using a TMP36 sensor. According to the gas level, the RGB LED changes color and the buzzer alerts the user. Sensor data is displayed on the Serial Monitor in CSV format.

---

## Hardware Required
- Arduino UNO
- Gas Sensor (MQ-2 Simulation)
- TMP36 Temperature Sensor
- RGB LED
- 3 × 220Ω Resistors
- Buzzer
- Breadboard
- Jumper Wires

---

## Circuit Connections

### Gas Sensor
- AOUT → A0
- VCC → 5V
- GND → GND

### TMP36
- Left Pin → 5V
- Middle Pin → A1
- Right Pin → GND

### RGB LED
- Red → D8
- Green → D9
- Blue → D10
- Common Cathode → GND

### Buzzer
- Positive → D7
- Negative → GND

---

## Working

1. Reads gas sensor value from A0.
2. Reads temperature from TMP36.
3. Displays sensor data on the Serial Monitor.
4. Green LED indicates SAFE condition.
5. Yellow LED indicates MODERATE gas level.
6. Red LED and buzzer indicate DANGER.

---

## Severity Levels

| Gas Value | Status | LED | Buzzer |
|-----------|--------|-----|---------|
| Below 300 | SAFE | Green | OFF |
| 300–599 | MODERATE | Yellow | Slow Beep |
| 600 and above | DANGER | Red | Fast Beep |

---

## Serial Monitor Output

```
Timestamp,Gas Value,Temperature(C),Severity
0,215,23.2,SAFE
2000,435,23.4,MODERATE
4000,710,24.1,DANGER
```

---

## Note

This project was implemented in Tinkercad using the available Gas Sensor and TMP36 sensor. Since Tinkercad does not support DHT11 and Bluetooth simulation, TMP36 is used instead of DHT11, and Bluetooth alerts are demonstrated as sample notifications.

---

## Author

**Name:** Mohit Kumar

**Course:** IoT Summer School 2026
