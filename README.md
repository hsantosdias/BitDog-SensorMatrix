# BitDog-SensorMatrix

## Visão Geral

O BitDog-SensorMatrix é um sistema de monitoramento ambiental baseado no Raspberry Pi Pico. O sistema coleta dados de diversos sensores e fornece alertas quando determinados limites são ultrapassados.

## Sensores Implementados

- **Temperatura**: Medição em graus Celsius
- **Umidade**: Medição percentual
- **Som**: Medição em decibéis (dB)
- **Luminosidade**: Medição em lux
- **Movimento**: Detecção binária (sim/não)
- **Chama**: Detecção binária (sim/não)
- **Geolocalização**: Coordenadas de latitude e longitude

## Funcionalidades

- Coleta de dados em intervalos regulares (configurável)
- Cálculo de médias móveis para filtragem de ruído
- Sistema de alertas com limites configuráveis
- Timestamp para todas as medições
- Interface de texto via UART/USB

## Requisitos de Hardware

- Raspberry Pi Pico W
- Sensores compatíveis (ou simulados para desenvolvimento)

## Compilação e Instalação

### Pré-requisitos

- SDK do Raspberry Pi Pico
- CMake 3.13 ou superior
- Ferramentas de desenvolvimento ARM GCC

### Passos para Compilação

1. Clone o repositório:

   ```
   git clone https://github.com/hsantosdias/BitDog-SensorMatrix.git
   cd BitDog-SensorMatrix
   ```
2. Crie e entre no diretório de build:

   ```
   mkdir build
   cd build
   ```
3. Configure e compile:

   ```
   cmake ..
   make
   ```
4. Conecte o Raspberry Pi Pico W em modo de bootloader (pressione BOOTSEL enquanto conecta)
5. Copie o arquivo UF2 gerado:

   ```
   cp BitDog-SensorMatrix.uf2 /RPI-RP2
   ```

## Configuração

O sistema possui várias constantes configuráveis no código:

- `AMOSTRAGEM_MS`: Intervalo entre medições em milissegundos
- `MAX_AMOSTRAS`: Número de amostras para cálculo da média móvel
- Limiares de alerta para cada sensor

## Uso

Após a instalação, o sistema iniciará automaticamente a coleta de dados. A saída será exibida via interface serial USB ou UART, dependendo da configuração.

Para visualizar os dados:

1. Conecte o dispositivo ao computador via USB
2. Abra um terminal serial (115200 baud rate):

   ```
   minicom -b 115200 -o -D /dev/ttyACM0
   ```

   ou

   ```
   screen /dev/ttyACM0 115200
   ```

## Contribuição

Contribuições são bem-vindas! Por favor, abra um issue para discutir mudanças importantes antes de submeter um pull request.
