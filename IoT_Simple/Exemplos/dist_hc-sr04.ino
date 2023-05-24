const int pinoTrigger = 2; // Pino de trigger do sensor
const int pinoEcho = 3;    // Pino de echo do sensor

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(pinoTrigger, OUTPUT); // Define o pino de trigger como saída
  pinMode(pinoEcho, INPUT);     // Define o pino de echo como entrada
}

void loop() {
  digitalWrite(pinoTrigger, LOW); // Garante que o pino de trigger esteja em estado baixo
  delayMicroseconds(2);

  digitalWrite(pinoTrigger, HIGH); // Envia um pulso de 10 microssegundos no pino de trigger
  delayMicroseconds(10);
  digitalWrite(pinoTrigger, LOW);

  long duracao = pulseIn(pinoEcho, HIGH); // Mede a duração do pulso de echo
  int distancia = duracao * 0.034 / 2;    // Calcula a distância em centímetros

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  delay(1000); // Aguarda por 1 segundo
}
