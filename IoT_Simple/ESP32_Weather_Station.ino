/*
  Project Title: ESP32 Weather Station
  Author: Francisco Soares
  Affiliation: ESTGL - Escola Superior de Tecnologia e Gestão de Lamego

  Description:
  This Arduino sketch turns an ESP32 into a weather station that measures temperature, humidity, pressure, and altitude. It utilizes sensors commonly found in cheap Chinese Arduino sensor kits, including a DHT sensor for temperature and humidity, and a BMP085/BMP180 sensor for pressure and altitude. The sensor readings are displayed on both a web server and an OLED display.

  Materials Needed:
  - 1x ESP32
  - 1x DHT Sensor (e.g., DHT11, DHT22)
  - 1x BMP085/BMP180 Sensor
  - Jumper wires

  Connections:
  - Connect the DHT sensor to pin DHT_PIN of the ESP32.
  - Connect the BMP085/BMP180 sensor to the I2C pins (SDA and SCL) of the ESP32.

  Enjoy monitoring the weather with your ESP32 Weather Station!
*/

#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHT_PIN 14       // DHT sensor pin
#define DHT_TYPE DHT11   // DHT sensor type

#define BMP_SDA 21       // BMP085/BMP180 SDA pin
#define BMP_SCL 22       // BMP085/BMP180 SCL pin

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

WebServer server(80);

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_BMP085 bmp;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float temperature = 0.0;
float humidity = 0.0;
float pressure = 0.0;
float altitude = 0.0;

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>ESP32 Weather Station</h1>";
  html += "<h2>Sensor Readings</h2>";
  html += "<p>Temperature: " + String(temperature) + " °C</p>";
  html += "<p>Humidity: " + String(humidity) + " %</p>";
  html += "<p>Pressure: " + String(pressure) + " hPa</p>";
  html += "<p>Altitude: " + String(altitude) + " m</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  // Initialize DHT sensor
  dht.begin();

  // Initialize BMP085/BMP180 sensor
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    while (1);
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Start the server
  server.on("/", handleRoot);
  server.begin();

  // Initialize display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 Weather");
  display.println(" Station");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // Read temperature and humidity from DHT sensor
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Read pressure and altitude from BMP085/BMP180 sensor
  pressure = bmp.readPressure() / 100.0;
  altitude = bmp.readAltitude();

  // Update display
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Temperature: " + String(temperature) + " C");
  display.println("Humidity: " + String(humidity) + " %");
  display.println("Pressure: " + String(pressure) + " hPa");
  display.println("Altitude: " + String(altitude) + " m");
  display.display();

  server.handleClient();
}
