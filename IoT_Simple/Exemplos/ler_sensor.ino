int pinoSensor = A0; // Número do pino para o sensor analógico

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  int valorSensor = analogRead(pinoSensor); // Lê o valor do sensor
  Serial.print("Valor do Sensor: ");
  Serial.println(valorSensor);
  delay(1000); // Espera por 1 segundo
}
