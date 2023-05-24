int pinoTilt = 2; // Pino digital conectado ao sensor de inclinação

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(pinoTilt, INPUT); // Define o pino do sensor de inclinação como entrada
}

void loop() {
  int estadoTilt = digitalRead(pinoTilt); // Lê o estado do sensor de inclinação

  if (estadoTilt == HIGH) {
    Serial.println("Inclinação detectada!");
  } else {
    Serial.println("Nenhuma inclinação detectada.");
  }

  delay(1000); // Aguarda por 1 segundo
}
