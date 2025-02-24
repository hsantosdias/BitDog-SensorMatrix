#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sensores.h"

int main(void) {
    float medTemp, medUmid;

    // Inicializa a semente para números aleatórios
    srand(time(NULL));

    while (1) {
        medTemp = obterTemperatura();
        medUmid = obterUmidade();
        // Exibe as medições de temperatura e umidade no terminal separadamente
        // mostrarTemperatura(medTemp);
        apresentarMedicoes(medTemp, medUmid);

        sleep(1); // Aguarda 1 segundo
    }

    return 0;
}
