int pinoLED = 13; // Número do pino para o LED

void setup() {
  pinMode(pinoLED, OUTPUT); // Define o pino do LED como saída
}

void loop() {
  digitalWrite(pinoLED, HIGH); // Liga o LED
  delay(1000); // Espera por 1 segundo
  digitalWrite(pinoLED, LOW); // Desliga o LED
  delay(1000); // Espera por 1 segundo
}
