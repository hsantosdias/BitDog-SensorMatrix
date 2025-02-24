#include <stdio.h>
#include <stdlib.h>
#include "sensores.h"

// Gera um valor aleatório para a temperatura entre 25.0°C e 27.0°C
float obterTemperatura(void) {
    return 25.0f + ((float)rand() / (float)RAND_MAX) * 2.0f;
}

// Gera um valor aleatório para a umidade entre 65.0% e 70.0%
float obterUmidade(void) {
    return 65.0f + ((float)rand() / (float)RAND_MAX) * 5.0f;
}

// Exibe a temperatura no terminal
void mostrarTemperatura(float tempMedida) {
    printf("Temperatura medida: %.2f°C\n", tempMedida);
}

// Exibe a umidade no terminal
void mostrarUmidade(float umidMedida) {
    printf("Umidade medida: %.2f%%\n", umidMedida);
}

// Apresenta as medições de temperatura e umidade
void apresentarMedicoes(float tempMedida, float umidMedida) {
    mostrarTemperatura(tempMedida);
    mostrarUmidade(umidMedida);
}
