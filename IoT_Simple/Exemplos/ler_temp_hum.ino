#include <DHT.h>

#define DHTPIN 2      // Pino de dados do sensor
#define DHTTYPE DHT11 // Tipo do sensor DHT

DHT dht(DHTPIN, DHTTYPE); // Criação de um objeto DHT

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  dht.begin();        // Inicializa o sensor DHT
}

void loop() {
  float temperatura = dht.readTemperature(); // Lê a temperatura em graus Celsius
  float humidade = dht.readHumidity();       // Lê a humidade relativa do ar

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");

  Serial.print("Humidade: ");
  Serial.print(humidade);
  Serial.println(" %");

  delay(2000); // Espera 2 segundos entre as leituras
}
