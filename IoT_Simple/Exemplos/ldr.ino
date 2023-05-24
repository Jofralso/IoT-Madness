int pinoLDR = A0; // Pino analógico conectado ao LDR

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  int valorLDR = analogRead(pinoLDR); // Lê o valor do sensor de luz

  Serial.print("Valor do LDR: ");
  Serial.println(valorLDR);

  delay(1000); // Aguarda por 1 segundo
}
