/*
 * Authors:
 *   Seif Karmy      - https://www.linkedin.com/in/seifkarmy/
 *   Mahmoud Darwish - https://www.linkedin.com/in/mahmoud-darwish-a264a51b1/
 *   Zeyad Mohamed   - https://www.linkedin.com/in/zyad-mohamed-353642253/
 */

#include <LiquidCrystal.h>

// -------- Stepper Motor --------
#define dirPin 3
#define stepPin 2
// -------- DC Motor --------
const int motorIn1 = 5;
const int motorIn2 = 6;

// -------- Ultrasonic Sensor --------
const int trigPin = 12;
const int echoPin = 13;

// -------- LCD --------
// LiquidCrystal lcd(10, 11, A2, A3, A4, A5);

// -------- LEDs --------
const int led1 = 7;
const int led2 = 8;

// -------- Stepper control --------
#define stepsPerRevolution 200 



void setup() {
 
  // DC motor pin
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);


  // Ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // LCD
  // lcd.begin(16, 2);
  // lcd.clear();
  //serial inial
  Serial.begin(9600);
}

void loop() {
 // Rotate one revolution clockwise
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);  // Controls speed (lower = faster)
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
  delay(1000);  // Pause for 1 second

  // Rotate one revolution counterclockwise
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
  delay(1000); 
  // --- Ultrasonic: measure distance ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  Serial.print("Distance ");
  Serial.println(distance);
  Serial.println("..........................");
  // --- DC Motor control ---
  if (distance < 30) {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
 
    // lcd.clear();
    // lcd.setCursor(0, 0);
    // lcd.print("Stop");
    Serial.println("Stop");
    Serial.println("..........................");
  } else {
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);

    // lcd.clear();
    // lcd.setCursor(0, 0);
    // lcd.print("Running...");
    Serial.println("Running");
    Serial.println("..........................");
  }

  // --- LEDs blink ---
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(500);
}
