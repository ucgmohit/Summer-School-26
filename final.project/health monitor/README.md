# Q47: Heart Rate & SpO2 Monitor (Simulation)

## Problem Statement

The objective of this project is to design a health monitoring prototype that measures heart rate and oxygen level.

The original system uses a MAX30102 pulse oximeter sensor.

Since Cirkit Designer does not support MAX30102 simulation, an LDR sensor is used as an analog sensor to simulate changing pulse readings.

This project is only for learning purposes and is not a medical device.

---

# Components Used

* Arduino UNO
* LDR (Photoresistor) for sensor simulation
* 10kΩ resistor
* Red LED (Alert indicator)
* Green LED (Normal indicator)
* Buzzer
* Breadboard
* Jumper wires

---

# Circuit Connections

## LDR Sensor

| LDR Connection | Arduino   |
| -------------- | --------- |
| One terminal   | 5V        |
| Other terminal | A0        |
| 10kΩ resistor  | A0 to GND |

The LDR provides analog values that represent changing sensor readings.

---

## Red LED (Alert)

| LED Pin  | Arduino                   |
| -------- | ------------------------- |
| Positive | D8                        |
| Negative | GND through 220Ω resistor |

---

## Green LED (Normal)

| LED Pin  | Arduino                   |
| -------- | ------------------------- |
| Positive | D9                        |
| Negative | GND through 220Ω resistor |

---

## Buzzer

| Buzzer Pin | Arduino |
| ---------- | ------- |
| Positive   | D10     |
| Negative   | GND     |

---

# Working Principle

1. The LDR reads analog values from the environment.

2. The Arduino converts the analog value into simulated health readings.

3. The system calculates:

   * Heart Rate (BPM)
   * SpO₂ percentage

4. A rolling average of 5 readings is used to reduce noise.

5. If readings are outside the normal range:

* Red LED turns ON.
* Buzzer gives an alert.

6. If readings are normal:

* Green LED remains ON.

---

# Health Alert Logic

## Normal Condition

Heart Rate:

```
50 BPM - 120 BPM
```

SpO₂:

```
Above 94%
```

Action:

```
Green LED ON
Buzzer OFF
```

---

## Abnormal Condition

Heart Rate:

```
Below 50 BPM
or
Above 120 BPM
```

OR

SpO₂:

```
Below 94%
```

Action:

```
Red LED ON
Buzzer ON
```

---

# Data Output Format

The readings are displayed on Serial Monitor.

Example:

```
========== HEALTH MONITOR ==========
Heart Rate : 78 BPM
SpO2       : 98 %
Status     : NORMAL
====================================
```

---

Alert Example:

```
========== HEALTH MONITOR ==========
Heart Rate : 130 BPM
SpO2       : 91 %
Status     : WARNING
Alert      : Abnormal Reading
====================================
```

---

# Rolling Average Algorithm

To reduce sensor noise:

1. Five sensor readings are collected.
2. The values are added.
3. The average value is calculated.
4. The average value is used for final output.

Formula:

```
Average =
(R1 + R2 + R3 + R4 + R5) / 5

```

Content:

```
Time,Heart_Rate,SpO2,Status
1000,75,98,NORMAL
2000,82,97,NORMAL
3000,130,92,WARNING
4000,65,99,NORMAL
5000,45,93,WARNING
```

---

# Limitations

* MAX30102 sensor is not available in Cirkit Designer.
* LDR is used only as a simulation sensor.
* This project is not suitable for real medical monitoring.

---

# Future Improvements

* Use actual MAX30102 sensor.
* Add OLED/LCD display.
* Add Bluetooth/Wi-Fi connectivity.
* Store health data on cloud.
* Create a mobile health monitoring application.

---

# Conclusion

This project demonstrates the basic concept of an IoT health monitoring system.

The Arduino reads sensor data, processes the values, applies filtering, and provides alerts when abnormal conditions are detected.

The simulation helps understand sensor interfacing and IoT healthcare applications.
