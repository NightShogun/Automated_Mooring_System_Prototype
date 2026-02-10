Automated Mooring System Architecture
Project Overview

This project prototype addresses the safety hazards and operational inefficiencies inherent in traditional vessel mooring. Conventional manual methods involving ropes and wires are a primary cause of port operation incidents, necessitating automated alternatives. This system utilizes an Arduino Uno to manage a closed-loop control system that simulates automated berthing using magnetic hooks.
Core Features

    Dynamic Wave Simulation: Employs a stepper motor with an attached "swaying wing" to mimic the rhythmic movement of water.

    Sonar-Based Distance Measurement: Uses an HC-SR04 ultrasonic sensor to determine the vessel's proximity to the quay.

    Automated Vessel Pulling: Controls a DC motor to simulate the mechanical pulling of a vessel toward the dock.

    Conceptual Magnetic Stabilization: Uses alternating LED patterns to signify the active engagement of magnetic stabilization hooks.

    Real-Time Data Monitoring: Transmits distance readings and operational status via serial communication for debugging and observation.

Hardware Component Specifications
Component	Function	Detail
Arduino Uno	Central Control Unit	

Processes all sensor inputs and manages actuator outputs.
Stepper Motor	Wave Simulation	

Operates at 1.8° per step (200 steps/revolution) using a NEMA17 series model.
Ultrasonic Sensor	Sonar Ranging	

HC-SR04 sensor with a range of 2 cm to 400 cm.
DC Motor	Pulling Mechanism	

Managed via an L298N H-Bridge driver for bidirectional control.
LED Indicators	Status Feedback	

Two LEDs (Pins 7 and 8) providing visual cues for system activity.
System Architecture & Pin Mapping

The system logic is defined by the following Arduino pin assignments:

    Stepper Motor: Step Pin (2), Direction Pin (3).

    DC Motor: MotorIn1 (5), MotorIn2 (6).

    Ultrasonic Sensor: Trig Pin (12), Echo Pin (13).

    LEDs: LED1 (7), LED2 (8).

Operational Logic

The system follows a continuous loop() cycle:

    Wave Simulation: The stepper motor completes one full revolution (200 steps) clockwise, pauses for 1 second, and then completes one revolution counter-clockwise.

    Distance Calculation: The system triggers a 10µs pulse and calculates distance using the formula: distance=(duration×0.034)/2.

    Motor Control:

        If the distance is less than 30 cm, the DC motor stops.

        If the distance is 30 cm or greater, the DC motor runs to pull the vessel.

    Feedback: The LEDs blink in an alternating 500ms pattern to indicate the system and stabilization hooks are active.
