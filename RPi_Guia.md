# Guia de Exemplos de IoT com Raspberry Pi e Sensores

Neste guia, vamos explorar diferentes exemplos de aplicação de Internet das Coisas (IoT) utilizando um Raspberry Pi e diversos sensores. Cada exemplo será apresentado em formato de código Python, mostrando como ler dados dos sensores e enviá-los para serviços de nuvem.

## Pré-requisitos

- Um Raspberry Pi configurado e conectado à rede.
- Sensores compatíveis com o Raspberry Pi. Exemplos: sensor de temperatura e umidade, sensor de movimento, sensor de luz, etc.
- Conhecimento básico de programação em Python.

## Exemplo 1: Sensor de Temperatura e Umidade

### Hardware necessário

- Raspberry Pi
- Sensor de temperatura e umidade (exemplo: DHT11 ou DHT22)

### Código

```python
import Adafruit_DHT

# Configurar o tipo de sensor e o pino GPIO conectado
sensor = Adafruit_DHT.DHT11
pino = 4

# Ler os dados do sensor
umid, temp = Adafruit_DHT.read_retry(sensor, pino)

# Exibir os valores lidos
if umid is not None and temp is not None:
    print('Temperatura={0:0.1f}°C  Umidade={1:0.1f}%'.format(temp, umid))
else:
    print('Falha ao ler os dados do sensor.')
```

## Exemplo 2: Sensor de Movimento

### Hardware necessário

- Raspberry Pi
- Sensor de movimento (exemplo: PIR - Passive Infrared Sensor)


### Código

```python
import RPi.GPIO as GPIO
import time

# Configurar o pino GPIO conectado ao sensor de movimento
pino = 18

# Configurar a biblioteca GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(pino, GPIO.IN)

while True:
    if GPIO.input(pino):
        print('Movimento detectado!')
    else:
        print('Nenhum movimento detectado.')
    time.sleep(0.1)

```

## Exemplo 3: Sensor de Luz

### Hardware necessário

- Raspberry Pi
- Sensor de luz (exemplo: LDR - Light-Dependent Resistor)

### Código

```python
import RPi.GPIO as GPIO

# Configurar o pino GPIO conectado ao sensor de luz
pino = 18

# Configurar a biblioteca GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(pino, GPIO.IN)

# Ler o valor da luminosidade
valor_luz = GPIO.input(pino)

# Exibir o valor da luminosidade
print('Valor da luminosidade:', valor_luz)
```

## Exemplo 4: Estação Meteorológica para Casa Inteligente

### Hardware necessário:

- Raspberry Pi
- Sensor de temperatura e humidade (exemplo: DHT11 ou DHT22)
- Sensor de pressão (exemplo: BMP180 ou BME280)
- Display LCD (16x2 ou 20x4)
- Breadboard e fios jumper

### Código:

``` python
# Importar bibliotecas necessárias
import Adafruit_DHT
import Adafruit_BMP.BMP085 as BMP085
import RPi.GPIO as GPIO
import time

# Configurar os pinos dos sensores
pino_dht = 4
bmp = BMP085.BMP085()

# Configurar GPIO para o display LCD
pino_rs = 26
pino_e = 19
pino_d4 = 13
pino_d5 = 6
pino_d6 = 5
pino_d7 = 11
num_colunas = 16
num_linhas = 2

# Inicializar o display LCD
lcd = Adafruit_CharLCD(pino_rs, pino_e, pino_d4, pino_d5, pino_d6, pino_d7, num_colunas, num_linhas)

# Loop principal
while True:
    # Ler temperatura e humidade
    humidade, temperatura = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, pino_dht)
    
    # Ler pressão
    pressao = bmp.read_pressure()
    
    # Exibir dados no display LCD
    lcd.clear()
    lcd.message('Temp: {0:.1f}°C\nHumidade: {1:.1f}%'.format(temperatura, humidade))
    time.sleep(2)
    lcd.clear()
    lcd.message('Pressão: {0:.2f} Pa'.format(pressao))
    time.sleep(2)

```

## Exemplo 5: Sistema de Alarme de Segurança

### Hardware necessário:
- Raspberry Pi
- Sensor de movimento (exemplo: PIR - Passive Infrared Sensor)
- Buzzer
- LED
- Breadboard e fios jumper

### Código

``` python

import RPi.GPIO as GPIO
import time

# Configurar os pinos dos sensores
pino_pir = 18
pino_buzzer = 21
pino_led = 17

# Configurar GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(pino_pir, GPIO.IN)
GPIO.setup(pino_buzzer, GPIO.OUT)
GPIO.setup(pino_led, GPIO.OUT)

# Loop principal
while True:
    if GPIO.input(pino_pir):
        print('Movimento detetado!')
        GPIO.output(pino_buzzer, GPIO.HIGH)
        GPIO.output(pino_led, GPIO.HIGH)
        time.sleep(1)
    else:
        GPIO.output(pino_buzzer, GPIO.LOW)
        GPIO.output(pino_led, GPIO.LOW)
        time.sleep(0.1)
```

## Exemplo 6: Sistema de Monitorização de Plantas

### Hardware necessário:

- Raspberry Pi
- Sensor de humidade do solo
- Resistor dependente da luz (LDR - Light-Dependent Resistor)
- Sensor de temperatura e humidade (exemplo: DHT11 ou DHT22)
- Display LCD (16x2 ou 20x4)
- Breadboard e fios jumper

### Código:

``` python

import Adafruit_DHT
import RPi.GPIO as GPIO
import time

# Configurar os pinos dos sensores
pino_dht = 4
pino_ldr = 18
pino_humidade = 21

# Configurar GPIO para o display LCD
pino_rs = 26
pino_e = 19
pino_d4 = 13
pino_d5 = 6
pino_d6 = 5
pino_d7 = 11
num_colunas = 16
num_linhas = 2

# Inicializar o display LCD
lcd = Adafruit_CharLCD(pino_rs, pino_e, pino_d4, pino_d5, pino_d6, pino_d7, num_colunas, num_linhas)

# Loop principal
while True:
    # Ler temperatura e humidade
    humidade, temperatura = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, pino_dht)
    
    # Ler nível de luz
    nivel_luz = GPIO.input(pino_ldr)
    
    # Ler nível de humidade do solo
    nivel_humidade = GPIO.input(pino_humidade)
    
    # Exibir dados no display LCD
    lcd.clear()
    lcd.message('Temp: {0:.1f}°C\nHumidade: {1:.1f}%'.format(temperatura, humidade))
    time.sleep(2)
    lcd.clear()
    lcd.message('Luz: {0}\nHumidade Solo: {1}'.format(nivel_luz, nivel_humidade))
    time.sleep(2)

```

## Considerações Finais

Esses são apenas alguns exemplos básicos para você começar a explorar a 
aplicação de IoT com Raspberry Pi e sensores. Existem muitos outros sensores 
disponíveis, assim como serviços de nuvem e plataformas para armazenar e 
processar os dados coletados.
