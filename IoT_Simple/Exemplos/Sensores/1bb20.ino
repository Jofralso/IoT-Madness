int pinoSom = A0; // Pino analógico conectado ao sensor de som

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  int valorSom = analogRead(pinoSom); // Lê o valor do sensor de som

  Serial.print("Valor do Sensor de Som: ");
  Serial.println(valorSom);

  delay(1000); // Aguarda por 1 segundo
}
