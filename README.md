# Automated Mooring System Architecture

## Project Overview
[cite_start]Traditional vessel mooring methods relying on manual operations (lines, ropes, and wires) present significant safety hazards and operational inefficiencies[cite: 6]. [cite_start]These conventional approaches are a leading cause of incidents in port operations[cite: 7]. [cite_start]This prototype system is designed as a closed-loop control system orchestrated by an Arduino Uno to simulate automated berthing using magnetic hooks[cite: 10].

## Core Features
* [cite_start]**Wave Simulation**: Uses a stepper motor with a "swaying wing" to mimic the rhythmic movement of water waves[cite: 26, 27].
* [cite_start]**Distance Measurement**: Utilizes sonar principles with an HC-SR04 sensor to determine vessel proximity[cite: 34, 35].
* [cite_start]**Automated Pulling**: Employs a DC motor to simulate the mechanical action of bringing a vessel toward the quay[cite: 51].
* [cite_start]**Status Indicators**: Alternating LED patterns visually signify the engagement of conceptual magnetic hooks used for stabilization[cite: 68, 142, 144].
* [cite_start]**Real-time Monitoring**: Transmits distance readings and operational data via serial communication[cite: 20].

## Hardware Component Specifications
* [cite_start]**Central Control**: Arduino Uno microcontroller acts as the brain processing all inputs and managing outputs[cite: 13].
* [cite_start]**Stepper Motor**: NEMA17 series providing 1.8 degrees per step (200 steps per full revolution)[cite: 28].
* [cite_start]**Ultrasonic Sensor**: HC-SR04 with a reliable measurement range of 2 cm to 400 cm[cite: 48].
* [cite_start]**Motor Driver**: L298N H-Bridge module to provide high-power signals to the DC motor[cite: 53, 55].
* [cite_start]**Speed of Sound Conversion**: The system uses 0.034 cm/µs at $20^{\circ}C$ for distance calculations[cite: 47, 48, 111].

## System Architecture & Pin Mapping
The following pin assignments are utilized by the Arduino Uno control unit:
* [cite_start]**Stepper Motor**: Step Pin (2), Direction Pin (3)[cite: 160, 162].
* [cite_start]**DC Motor Control**: MotorIn1 (5), MotorIn2 (6)[cite: 163, 165].
* [cite_start]**Ultrasonic Sensor**: Trig Pin (12), Echo Pin (13)[cite: 167, 169].
* [cite_start]**LED Indicators**: LED1 (7), LED2 (8)[cite: 171, 172].

## Operational Logic
[cite_start]The `loop()` function executes a continuous operational cycle[cite: 191]:
1. [cite_start]**Environmental Simulation**: The stepper motor completes 200 steps clockwise, pauses for 1 second, and completes 200 steps counter-clockwise[cite: 194, 197, 199, 201].
2. [cite_start]**Sensing**: The ultrasonic sensor triggers a pulse to measure distance[cite: 207]. 
   [cite_start]The distance is calculated using the formula: $$distance = (duration \times 0.034) / 2$$[cite: 110, 111].
3. **Control Decision**: 
   - [cite_start]If the calculated distance is **less than 30 cm**, the DC motor is set to a "Stop" state[cite: 208, 209].
   - [cite_start]If the distance is **30 cm or greater**, the DC motor is set to "Running" to pull the vessel[cite: 209].
4. [cite_start]**Visual Feedback**: LEDs blink in an alternating pattern for 500 milliseconds each to indicate system activity and stabilization[cite: 150, 210, 211].
