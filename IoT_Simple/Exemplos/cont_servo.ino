#include <Servo.h>

int pinoServo = 9; // Número do pino para o servo motor
Servo servo; // Cria um objeto servo

void setup() {
  servo.attach(pinoServo); // Conecta o servo ao pino
}

void loop() {
  servo.write(0); // Move o servo para 0 graus
  delay(1000); // Espera por 1 segundo
  servo.write(90); // Move o servo para 90 graus
  delay(1000); // Espera por 1 segundo
  servo.write(180); //
