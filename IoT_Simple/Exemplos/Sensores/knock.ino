int pinoKnock = 2; // Pino digital conectado ao sensor de impacto

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(pinoKnock, INPUT); // Define o pino do sensor de impacto como entrada
}

void loop() {
  int estadoKnock = digitalRead(pinoKnock); // Lê o estado do sensor de impacto

  if (estadoKnock == HIGH) {
    Serial.println("Impacto detectado!");
  } else {
    Serial.println("Nenhum impacto detectado.");
  }

  delay(1000); // Aguarda por 1 segundo
}
