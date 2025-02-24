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

        // Apresenta os novos sensores simulados
        apresentarNovosSensores();

        sleep(2); // Aguarda 2 segundos para visualização dos dados
        printf("-----------------------------\n");
    }

    return 0;
}
