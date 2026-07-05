# LED Blink Project

## Project Title
LED Blink with Potentiometer Speed Control

## Hardware Required
- Arduino Uno
- LED
- 220Ω Resistor
- Potentiometer (10kΩ)
- Breadboard
- Jumper Wires
- USB Cable

## Circuit Diagram Description
1. Connect the LED anode (long leg) to Arduino pin 13 through a 220Ω resistor.
2. Connect the LED cathode (short leg) to GND.
3. Connect one side of the potentiometer to 5V.
4. Connect the other side of the potentiometer to GND.
5. Connect the middle pin (wiper) of the potentiometer to analog pin A0.

## How to Upload Code
1. Connect the Arduino Uno to the computer using a USB cable.
2. Open Arduino IDE.
3. Open the `led_blink.ino` file.
4. Select **Tools → Board → Arduino Uno**.
5. Select the correct COM Port under **Tools → Port**.
6. Click the **Upload** button.
7. Open the Serial Monitor at 9600 baud to view the blink count.

## Expected Output
- The LED blinks continuously.
- The potentiometer changes the blink speed.
- The Serial Monitor displays:
  ```
  Blink count: 1
  Blink count: 2
  Blink count: 3
  ```
- Rotating the potentiometer makes the LED blink faster or slower.

## Troubleshooting Tips
1. Check that the correct COM port and Arduino board are selected.
2. Verify all circuit connections, especially the LED polarity and potentiometer wiring.
3. Ensure the Serial Monitor baud rate is set to **9600**.
