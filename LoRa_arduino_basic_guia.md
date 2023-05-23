# Guia de Utilização de Dispositivos ESP32 TTGO LoRa
Neste guia, exploraremos o uso de dois dispositivos ESP32 TTGO LoRa para criar uma comunicação sem fio de longo alcance utilizando a tecnologia LoRa (Long Range). Abordaremos dois cenários diferentes: comunicação ponto a ponto e comunicação em rede com um gateway LoRa.

## Pré-requisitos

- Dois dispositivos ESP32 TTGO LoRa
- Arduino IDE instalada
- Biblioteca LMIC (LoRaWAN-in-C, disponível no Gerenciador de Bibliotecas da Arduino IDE)
- Conhecimentos básicos de programação e eletrônica

## Cenário 1: Comunicação Ponto a Ponto

### Descrição

Neste cenário, configuraremos um dispositivo ESP32 TTGO LoRa como transmissor e o outro como receptor. O transmissor enviará uma mensagem por meio da tecnologia LoRa, e o receptor receberá essa mensagem.

### Configuração do Transmissor
1. Conecte o dispositivo ESP32 TTGO LoRa ao computador via USB.
2. Abra a Arduino IDE.
3. Selecione a placa **"ESP32 Dev Module"** no menu **"Ferramentas" > "Placa"**.
4. Abra o exemplo **"arduino-lmic"** na Arduino IDE: **Arquivo > Exemplos > LMIC-Arduino > ttn-abp**.
5. Edite as configurações do transmissor de acordo com a sua rede LoRaWAN:

- const char *devAddr - endereço do dispositivo LoRaWAN
- const char *nwkSKey - chave de sessão da rede (Network Session Key)
- const char *appSKey - chave de aplicação (App Session Key)

6. Faça o upload do código para o dispositivo ESP32 TTGO LoRa.

### Configuração do Receptor

1. Conecte o segundo dispositivo ESP32 TTGO LoRa ao computador via USB.
2. Repita os passos de 2 a 4 da seção "Configuração do Transmissor".
3. Abra o exemplo "arduino-lmic" na Arduino IDE: Arquivo > Exemplos > LMIC-Arduino > ttn-abp.
4. Edite as configurações do receptor de acordo com a sua rede LoRaWAN:

- **const char *devAddr** - endereço do dispositivo LoRaWAN
- **const char *nwkSKey** - chave de sessão da rede (Network Session Key)
- **const char *appSKey** - chave de aplicação (App Session Key)

5. Faça o upload do código para o segundo dispositivo ESP32 TTGO LoRa.

## Funcionamento
Após configurar o transmissor e o receptor, eles estarão prontos para se comunicarem. O transmissor enviará a mensagem definida no código, e o receptor receberá essa mensagem.

## Tecnologias Associadas
**LoRa:** Uma tecnologia de comunicação sem fio de longo alcance que permite a transmissão de dados em distâncias maiores em comparação com outras tecnologias sem fio, como o Wi-Fi ou Bluetooth.

**LoRaWAN:** Uma rede de área ampla de baixa potência (LPWAN) baseada na tecnologia LoRa, que permite a conexão de dispositivos de IoT a uma rede de longo alcance e baixo consumo de energia.

# Cenário 2: Comunicação em Rede com Gateway LoRa

## Descrição

Neste cenário, utilizaremos um dispositivo ESP32 TTGO LoRa como nó (node) e um segundo dispositivo ESP32 TTGO LoRa como gateway LoRa. O nó enviará mensagens para o gateway, que retransmitirá essas mensagens para um servidor LoRaWAN.

###  Configuração do Nó
1. Conecte o dispositivo ESP32 TTGO LoRa (nó) ao computador via USB.
2. Abra a Arduino IDE.
3. Selecione a placa "ESP32 Dev Module" no menu "Ferramentas" > "Placa".
4. Abra o exemplo "arduino-lmic" na Arduino IDE: Arquivo > Exemplos > LMIC-Arduino > ttn-abp.
5. Edite as configurações do nó de acordo com a sua rede LoRaWAN:

- `const char *devAddr` - endereço do dispositivo LoRaWAN
- `const char *nwkSKey` - chave de sessão da rede (Network Session Key)
- `const char *appSKey` - chave de aplicação (App Session Key)
6. Faça o upload do código para o dispositivo ESP32 TTGO LoRa (nó).

### Configuração do Gateway

1. Conecte o segundo dispositivo ESP32 TTGO LoRa (gateway) ao computador via USB.
2. Repita os passos de 2 a 4 da seção "Configuração do Nó".
3. Abra o exemplo "arduino-lmic" na Arduino IDE: Arquivo > Exemplos > LMIC-Arduino > ttn-abp.
4. Edite as configurações do gateway de acordo com a sua rede LoRaWAN:

- `const char *devAddr` - endereço do dispositivo LoRaWAN
- `const char *nwkSKey` - chave de sessão da rede (Network Session Key)
- `const char *appSKey` - chave de aplicação (App Session Key)

5. Faça o upload do código para o segundo dispositivo ESP32 TTGO LoRa (gateway).

## Funcionamento
Após configurar o nó e o gateway, o nó enviará mensagens para o gateway. O gateway retransmitirá essas mensagens para um servidor LoRaWAN, permitindo a comunicação em rede com outros dispositivos.

## Tecnologias Associadas
**Gateway LoRa**: Um dispositivo que recebe e retransmite mensagens de dispositivos LoRa para um servidor LoRaWAN. Ele é responsável por estender o alcance da rede LoRa e encaminhar os dados para a nuvem.

**LoRaWAN Server**: Um servidor responsável por gerenciar a rede LoRaWAN, autenticar dispositivos, rotear mensagens e armazenar os dados recebidos dos dispositivos de IoT.
