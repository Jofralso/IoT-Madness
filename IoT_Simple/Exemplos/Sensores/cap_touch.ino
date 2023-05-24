#include <CapacitiveSensor.h>

const int pinoEnvio = 4; // Pino de envio do sensor capacitivo
const int pinoRecepcao = 2; // Pino de recepção do sensor capacitivo

CapacitiveSensor sensor = CapacitiveSensor(pinoEnvio, pinoRecepcao); // Criação de um objeto sensor capacitivo

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  long valorToque = sensor.capacitiveSensor(30); // Lê o valor do toque capacitivo

  Serial.print("Valor de Toque: ");
  Serial.println(valorToque);

  delay(100); // Aguarda por 100 milissegundos
}
