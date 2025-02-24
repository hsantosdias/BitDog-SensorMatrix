#ifndef MEDICOES_H
#define MEDICOES_H

// Funções de medição e exibição de temperatura e umidade
float obterTemperatura(void);
float obterUmidade(void);
void mostrarTemperatura(float tempMedida);
void mostrarUmidade(float umidMedida);
void apresentarMedicoes(float tempMedida, float umidMedida);

// Tipos e funções para posição geográfica
typedef struct {
    int graus;
    int minutos;
    float segundos;
} Coordenada;

typedef struct {
    Coordenada latitude;
    Coordenada longitude;
} PosicaoGeografica;

PosicaoGeografica obterPosicaoGeografica(void);
void exibirPosicaoGeografica(PosicaoGeografica pos);

#endif // MEDICOES_H
