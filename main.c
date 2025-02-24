#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sensores.h"

int main(void) {
    float medTemp, medUmid;
    PosicaoGeografica posicao;

    // Inicializa a semente para números aleatórios
    srand(time(NULL));

    while (1) {
        medTemp = obterTemperatura();
        medUmid = obterUmidade();
        apresentarMedicoes(medTemp, medUmid);

        posicao = obterPosicaoGeografica();
        exibirPosicaoGeografica(posicao);

        sleep(1); // Aguarda 1 segundo
    }

    return 0;
}
