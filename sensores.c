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
// Para latitude: valores de 0 a 90 graus; para longitude: 0 a 180 graus.
PosicaoGeografica obterPosicaoGeografica(void) {
    PosicaoGeografica pos;

    pos.latitude.graus   = gerarInteiro(0, 90);
    pos.latitude.minutos = gerarInteiro(0, 59);
    pos.latitude.segundos= gerarValorFloat(60.0f);

    pos.longitude.graus   = gerarInteiro(0, 180);
    pos.longitude.minutos = gerarInteiro(0, 59);
    pos.longitude.segundos= gerarValorFloat(60.0f);

    return pos;
}

// Função que exibe a posição geográfica no terminal.
void exibirPosicaoGeografica(PosicaoGeografica pos) {
    printf("Latitude: %d° %d' %.2f\"\n", pos.latitude.graus, pos.latitude.minutos, pos.latitude.segundos);
    printf("Longitude: %d° %d' %.2f\"\n", pos.longitude.graus, pos.longitude.minutos, pos.longitude.segundos);
}
