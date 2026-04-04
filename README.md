# 2wheelRobotCar  
This project is an autonomous robot car capable of navigating environments using obstacle detection, line tracking, and user gesture control. The system integrates multiple sensors and actuators to demonstrate real-time decision-making on an embedded platform.

Features
Obstacle Avoidance – Uses ultrasonic sensor to detect objects and adjust path
Line Following – IR sensors track and follow a path
Gesture Control Toggle – Hand wave enables/disables the robot
Servo Scanning – Rotates sensor to decide best direction
Motor Control – PWM-based speed and direction control

Hardware Used
Arduino UNO
Ultrasonic sensor (HC-SR04)
2 IR line tracking sensors
Servo motor
2 DC motors + motor driver

Software / Concepts
Embedded C / Arduino
PWM motor control
Sensor fusion (combining ultrasonic + IR)
Real-time decision logic

How It Works:
The robot continuously reads sensor data:
If a hand gesture is detected → toggles robot ON/OFF
If line is detected → follows path
If obstacle detected → stops, scans left/right using servo, and chooses a clear path



