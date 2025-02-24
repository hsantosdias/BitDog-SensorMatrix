#ifndef MEDICOES_H
#define MEDICOES_H

// Declaração das funções de medição e exibição dos dados
float obterTemperatura(void);
float obterUmidade(void);
void mostrarTemperatura(float tempMedida);
void mostrarUmidade(float umidMedida);
void apresentarMedicoes(float tempMedida, float umidMedida);

#endif // MEDICOES_H
