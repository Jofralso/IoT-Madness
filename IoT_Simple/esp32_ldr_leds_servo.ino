/*
  Project Title: Light-Activated Servo Control
  Author: Francisco Soares
  Affiliation: ESTGL - Escola Superior de Tecnologia e Gestão de Lamego

  Description:
  This project demonstrates the control of a servo motor based on the intensity of light detected by an LDR (Light Dependent Resistor). 
  As the light level changes, the servo motor moves to different positions, providing a visual feedback.

  Materials Needed:
  - 1x ESP32-WROOM-32D (Development Kit)
  - 2x LEDs
  - 1x LDR (Light Dependent Resistor)
  - 1x 1kOhm Resistor
  - 2x 10kOhm Resistors
  - Jumpers
  - 1x Servo Motor

  Connections:
  - Connect the LDR to an analog input pin of the ESP32.
  - Connect the LEDs to digital output pins of the ESP32.
  - Connect the 1kOhm resistor in series with the LDR to create a voltage divider circuit.
  - Connect the 10kOhm resistors in series with the LEDs to limit the current flow.
  - Connect the servo motor to a PWM (Pulse Width Modulation) capable pin of the ESP32.

  Enjoy experimenting and learning with this project!
*/

#include <ESP32Servo.h>

#define LDR_PIN 32   		// LDR analog input pin
#define LED_PIN_1 33 		// LED 1 pin
#define LED_PIN_2 34    // LED 2 pin
#define SERVO_PIN 12 		// Servo motor control pin

Servo servo;       			// Servo object

void setup()
{
  Serial.begin(9600);     	/*Baud rate for serial communication*/
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  
  servo.attach(SERVO_PIN);
  servo.write(90); 			// define initial position to 90º
}

void loop()
{
  int ldrValue = analogRead(LDR_PIN);
  int servoAngle = map(ldrValue, 0, 1023, 0, 180);//Adjust 0-1023 to values between 0-4095 because of the ESP32 ADC
  Serial.print("LDR Output Value: ");
  Serial.println(ldrValue);
  // Adjust to the value in between the range of servoAngle
  if (ldrValue < 400) { 
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, LOW);
  } else {
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, HIGH);
  }
  servo.write(servoAngle);
  
  delay(100);
}
