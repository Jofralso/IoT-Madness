# Guia do Node-RED com a placa TTGO LoRa

## Passo 1: Configurar a placa TTGO LoRa

- Conecte a placa TTGO LoRa ao seu computador usando um cabo USB.
- Instale os drivers necessários, se necessário.

## Passo 2: Instalar o Node-RED

- Faça o download e instale o Node-RED seguindo o guia de instalação oficial: `https://nodered.org/docs/getting-started`

## Passo 3: Instalar o nó LoRaWAN para o Node-RED

- Abra o Node-RED em seu navegador da web (geralmente em `http://localhost:1880`).
- Clique no ícone de menu no canto superior direito e selecione "Gerenciar paletas".
- Vá para a guia "Instalar" e pesquise por "node-red-contrib-lora-gateway".
- Clique no botão "Instalar" para instalar o nó LoRaWAN.

## Passo 4: Configurar a conexão LoRaWAN

- Arraste e solte o nó "lora-gateway-config" da seção "lora-gateway" da paleta do Node-RED para a área de trabalho.
- Dê um duplo clique no nó para configurá-lo.
- Insira os detalhes necessários, como endereço do servidor, porta, ID da rede e plano de frequência para a sua rede LoRaWAN.
- Clique em "Concluído" para salvar a configuração.

## Passo 5: Criar um fluxo

- Arraste e solte um nó LoRaWAN na área de trabalho.
- Dê um duplo clique no nó e configure-o com as definições apropriadas, como o EUI do dispositivo, EUI da aplicação e chave da aplicação.
- Adicione quaisquer outros nós ou funções necessárias para processar os dados recebidos.
- Conecte os nós entre si para criar o fluxo desejado.

## Passo 6: Implementar o fluxo

- Clique no botão "Implementar" no canto superior direito do editor do Node-RED para implementar o seu fluxo.

## Passo 7: Monitorizar a placa TTGO LoRa

- Comece a monitorizar a saída no painel de depuração do Node-RED clicando no ícone de bug no canto superior direito.
- Você deverá ver os dados recebidos da placa TTGO LoRa no painel de depuração, à medida que ela envia dados através do LoRaWAN.

Parabéns! Você configurou com sucesso o Node-RED com a placa TTGO LoRa. Agora você pode personalizar o seu fluxo para processar e visualizar os dados recebidos da placa usando os nós e funções disponíveis no Node-RED.
