# 🚧 Smart Barrier System (Arduino-based)

This project simulates an automated parking or access gate, my first arduino project!
It uses an ultrasonic sensor to detect approaching objects and a servo motor to operate the barrier.

## ✧ Features & Engineering Logic
*   **Non-blocking Execution:** The system uses `millis()` instead of `delay()`. This ensures the microcontroller remains responsive to sensor inputs at all times, a critical practice in embedded systems engineering.
*   **State Management:** Implements a simple state logic to track whether the barrier is open or closed, preventing redundant commands to the servo.
*   **Real-time Calculation:** Converts ultrasonic pulse duration to distance using the speed of sound formula: $d = \frac{v \cdot t}{2}$.

## ✧ Hardware Used
*   **Microcontroller:** Arduino Uno
*   **Sensor:** HC-SR04 Ultrasonic Sensor
*   **Actuator:** SG90 Servo Motor

## ✧ Code Structure
- `ultrasound_sensor_bar.ino`: Main C++ logic with non-blocking timing.

## ✧ Future Improvements
- Implement a moving average filter for more stable distance readings.
- Add an I2C LCD screen to display the remaining "open" time.
