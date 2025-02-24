#include <stdio.h>
#include <stdlib.h>
#include "sensores.h"

// Função que simula a leitura da temperatura, gerando um valor variável entre 25.0°C e 27.0°C.
float obterTemperatura(void) {
    return 25.0f + ((float)rand() / (float)RAND_MAX) * 2.0f;
}

// Função que simula a leitura da umidade, gerando um valor variável entre 65.0% e 70.0%.
float obterUmidade(void) {
    return 65.0f + ((float)rand() / (float)RAND_MAX) * 5.0f;
}

// Função que exibe a temperatura no terminal.
void mostrarTemperatura(float tempMedida) {
    printf("Temperatura medida: %.2f°C\n", tempMedida);
}

// Função que exibe a umidade no terminal.
void mostrarUmidade(float umidMedida) {
    printf("Umidade medida: %.2f%%\n", umidMedida);
}

// Função que apresenta as medições de temperatura e umidade, chamando as funções específicas.
void apresentarMedicoes(float tempMedida, float umidMedida) {
    mostrarTemperatura(tempMedida);
    mostrarUmidade(umidMedida);
}

// Função auxiliar que gera um número inteiro aleatório entre 'min' e 'max' (inclusive).
int gerarInteiro(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Função auxiliar que gera um valor float aleatório entre 0.0 e 'max'.
float gerarValorFloat(float max) {
    return ((float)rand() / (float)RAND_MAX) * max;
}

// Função que simula a obtenção de uma posição geográfica.
// Para latitude: valores de 0 a 90 graus; para longitude: de 0 a 180 graus.
PosicaoGeografica obterPosicaoGeografica(void) {
    PosicaoGeografica pos;

    // Coordenadas fixas: 14° 51′ 57″ S, 40° 50′ 20″ O, com variação de ±2 segundos
    pos.latitude.graus   = 14;
    pos.latitude.minutos = 51;
    pos.latitude.segundos = 57.0f + (((float)rand() / (float)RAND_MAX) * 4.0f - 2.0f);

    pos.longitude.graus   = 40;
    pos.longitude.minutos = 50;
    pos.longitude.segundos = 20.0f + (((float)rand() / (float)RAND_MAX) * 4.0f - 2.0f);

    return pos;
}


// Função que exibe a posição geográfica no terminal.
void exibirPosicaoGeografica(PosicaoGeografica pos) {
    printf("Latitude: %d° %d' %.2f\"\n", pos.latitude.graus, pos.latitude.minutos, pos.latitude.segundos);
    printf("Longitude: %d° %d' %.2f\"\n", pos.longitude.graus, pos.longitude.minutos, pos.longitude.segundos);
}

// NOVOS SENSORES

// Simula um sensor de som, retornando um nível em decibéis entre 30 dB e 100 dB.
float obterNivelSom(void) {
    return 30.0f + ((float)rand() / (float)RAND_MAX) * 70.0f;
}

// Simula um sensor de movimento, retornando 1 (movimento detectado) ou 0 (sem movimento).
int detectarMovimento(void) {
    return rand() % 2;
}

// Simula um detector de chama, retornando 1 se houver chama detectada ou 0 caso contrário.
int detectarChama(void) {
    return rand() % 2;
}

// Simula um sensor de luminosidade, retornando um valor em lux entre 100 e 1000.
float obterLuminosidade(void) {
    return 100.0f + ((float)rand() / (float)RAND_MAX) * 900.0f;
}

// Exibe o nível de som no terminal.
void mostrarNivelSom(float nivelSom) {
    printf("Nível de som: %.2f dB\n", nivelSom);
}

// Exibe se há movimento detectado.
void mostrarMovimento(int movimento) {
    printf("Movimento detectado: %s\n", (movimento) ? "Sim" : "Não");
}

// Exibe se há chama detectada.
void mostrarChama(int chama) {
    printf("Chama detectada: %s\n", (chama) ? "Sim" : "Não");
}

// Exibe o valor de luminosidade no terminal.
void mostrarLuminosidade(float luminosidade) {
    printf("Luminosidade: %.2f lux\n", luminosidade);
}

// Agrupa a apresentação dos novos sensores, chamando cada função de exibição.
void apresentarNovosSensores(void) {
    float nivelSom = obterNivelSom();
    int movimento = detectarMovimento();
    int chama = detectarChama();
    float luminosidade = obterLuminosidade();

    mostrarNivelSom(nivelSom);
    mostrarMovimento(movimento);
    mostrarChama(chama);
    mostrarLuminosidade(luminosidade);
}
