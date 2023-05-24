#include <IRremote.h>

int pinoIR = 2; // Pino digital conectado ao receptor IR
IRrecv receptor(pinoIR); // Cria um objeto receptor IR

decode_results resultado; // Variável para armazenar o resultado da decodificação

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  receptor.enableIRIn(); // Inicializa o receptor IR
}

void loop() {
  if (receptor.decode(&resultado)) {
    Serial.print("Código recebido: ");
    Serial.println(resultado.value, HEX);
    receptor.resume(); // Reinicia o receptor IR para receber mais sinais
  }
}
