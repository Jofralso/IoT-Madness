int pinoPIR = 2; // Pino digital conectado ao sensor PIR

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(pinoPIR, INPUT); // Define o pino do sensor PIR como entrada
}

void loop() {
  int deteccaoMovimento = digitalRead(pinoPIR); // Lê o estado do sensor de movimento

  if (deteccaoMovimento == HIGH) {
    Serial.println("Movimento detectado!");
  } else {
    Serial.println("Nenhum movimento detectado.");
  }

  delay(1000); // Aguarda por 1 segundo
}
