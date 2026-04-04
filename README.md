# 2-Wheel Robot Car (Modular Robotics Platform)
## Overview

This project is a modular embedded robotics platform where each script implements a specific behavior. The system is designed to support testing, development, and integration of multiple navigation strategies in a scalable architecture.

## Features
1. Obstacle Avoidance – Utilizes an ultrasonic sensor to detect obstacles and dynamically adjust the robot’s path
2. Line Following – Uses IR sensors to track and follow predefined paths
3. Gesture Control Toggle – Hand wave detection enables or disables robot operation
4. Servo-Based Environment Scanning – Rotates the ultrasonic sensor to evaluate multiple directions before selecting a path
5. Motor Control – PWM-based speed and direction control for differential drive movement

## Hardware Used
- Arduino Uno
* Ultrasonic sensor (HC-SR04)
+ 2× IR line tracking sensors
- Servo motor
* 2× DC motors with motor driver

## Software & Concepts
- Embedded C / Arduino
* PWM motor control
+ Sensor fusion (ultrasonic + IR integration)
- Real-time decision-making logic
* State-based control system

## System Behavior

The robot continuously processes sensor inputs and executes actions based on environmental conditions:

1.  Detects a hand gesture to toggle the robot ON/OFF
2.  Follows a path when line tracking sensors detect a valid trajectory
   - When an obstacle is detected:
    - Stops movement
     - Performs a servo-based scan (left/right)
      - Selects the optimal direction based on distance measurements

## Purpose
- Explore multiple autonomous navigation strategies
* Develop a scalable and modular embedded system
+ Gain hands-on experience with sensor integration and real-time control 

## Future Improvements
- PID control for smoother line following
*  Integration with ESP32 for wireless control (Bluetooth/WiFi)
+ Camera-based navigation (OpenCV / Raspberry Pi)
- Improved obstacle detection using multiple sensors

