#include <ESP32Servo.h>

#define LDR_PIN A0   		// LDR analog input pin
#define LED_PIN_1 2 		// LED 1 pin
#define LED_PIN_2 3  		// LED 2 pin
#define SERVO_PIN 4  		// Servo motor control pin

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
  int servoAngle = map(ldrValue, 0, 1023, 0, 180);//Adjust 0-1023 to values between 0-4095b because of the ESP32 ADC
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