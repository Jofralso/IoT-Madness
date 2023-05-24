int pinoBotao = 2; // Número do pino para o botão
int pinoLED = 13; // Número do pino para o LED
int estadoBotao = 0; // Variável para armazenar o estado do botão

void setup() {
  pinMode(pinoBotao, INPUT); // Define o pino do botão como entrada
  pinMode(pinoLED, OUTPUT); // Define o pino do LED como saída
}

void loop() {
  estadoBotao = digitalRead(pinoBotao); // Lê o estado do botão

  if (estadoBotao == HIGH) { // Se o botão for pressionado
    digitalWrite(pinoLED, !digitalRead(pinoLED)); // Alterna o estado do LED
    delay(200); // Delay de debounce
  }
}
