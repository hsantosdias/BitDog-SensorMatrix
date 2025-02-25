#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hardware/rtc.h"
#include "hardware/adc.h"
#include "sensores.h"

// Definições de constantes para configuração
#define AMOSTRAGEM_MS 1000  // Intervalo entre medições em milissegundos
#define MAX_AMOSTRAS 10     // Número de amostras para média móvel

// Estrutura para armazenar histórico de leituras
typedef struct {
    float valores[MAX_AMOSTRAS];
    int indice;
    int preenchido;
} HistoricoLeituras;

// Inicializa um histórico de leituras
void inicializar_historico(HistoricoLeituras* historico) {
    for (int i = 0; i < MAX_AMOSTRAS; i++) {
        historico->valores[i] = 0.0f;
    }
    historico->indice = 0;
    historico->preenchido = 0;
}

// Adiciona uma leitura ao histórico e retorna a média
float adicionar_leitura(HistoricoLeituras* historico, float leitura) {
    historico->valores[historico->indice] = leitura;
    historico->indice = (historico->indice + 1) % MAX_AMOSTRAS;
    
    if (historico->indice == 0) {
        historico->preenchido = 1;
    }
    
    // Calcula a média
    float soma = 0.0f;
    int num_elementos = historico->preenchido ? MAX_AMOSTRAS : historico->indice;
    
    for (int i = 0; i < num_elementos; i++) {
        soma += historico->valores[i];
    }
    
    return soma / num_elementos;
}

int main(void) {
    // Inicialização do hardware
    stdio_init_all();
    
    // Inicialização do ADC
    adc_init();
    adc_set_temp_sensor_enabled(true);
    
    // Inicialização do RTC
    datetime_t t = {
        .year  = 2025,
        .month = 2,
        .day   = 24,
        .dotw  = 1, // 0 é domingo, 1 é segunda
        .hour  = 12,
        .min   = 0,
        .sec   = 0
    };
    rtc_init();
    rtc_set_datetime(&t);

    // Registros para cálculo de médias móveis
    HistoricoLeituras hist_temp, hist_umid, hist_som, hist_luz;
    inicializar_historico(&hist_temp);
    inicializar_historico(&hist_umid);
    inicializar_historico(&hist_som);
    inicializar_historico(&hist_luz);
    
    // Variáveis para medições
    float temp_atual, umid_atual, som_atual, luz_atual;
    float temp_media, umid_media, som_media, luz_media;
    int movimento, chama;
    PosicaoGeografica posicao;
    
    // Variáveis para controle de alertas
    int alerta_temp = 0, alerta_som = 0, alerta_chama = 0;
    float limiar_temp_alta = 26.5f;
    float limiar_som_alto = 85.0f;

    printf("\n===== BitDog-SensorMatrix v1.0 =====\n");
    printf("Iniciando monitoramento de sensores...\n\n");

    // Inicializa a semente para números aleatórios
    srand(time(NULL));

    while (1) {
        // Obtenção dos dados dos sensores
        temp_atual = obterTemperatura();
        umid_atual = obterUmidade();
        som_atual = obterNivelSom();
        luz_atual = obterLuminosidade();
        movimento = detectarMovimento();
        chama = detectarChama();
        posicao = obterPosicaoGeografica();
        
        // Cálculo de médias móveis
        temp_media = adicionar_leitura(&hist_temp, temp_atual);
        umid_media = adicionar_leitura(&hist_umid, umid_atual);
        som_media = adicionar_leitura(&hist_som, som_atual);
        luz_media = adicionar_leitura(&hist_luz, luz_atual);
        
        // Timestamp atual
        datetime_t t_atual;
        rtc_get_datetime(&t_atual);
        
        // Exibição dos dados com timestamp
        printf("[%02d:%02d:%02d] Leituras dos sensores:\n", 
               t_atual.hour, t_atual.min, t_atual.sec);
        
        // Exibição dos valores atuais e médias
        printf("Temperatura: %.2f°C (média: %.2f°C)\n", temp_atual, temp_media);
        printf("Umidade: %.2f%% (média: %.2f%%)\n", umid_atual, umid_media);
        printf("Nível de som: %.2f dB (média: %.2f dB)\n", som_atual, som_media);
        printf("Luminosidade: %.2f lux (média: %.2f lux)\n", luz_atual, luz_media);
        
        // Exibição dos valores binários
        printf("Movimento detectado: %s\n", movimento ? "SIM" : "não");
        printf("Chama detectada: %s\n", chama ? "SIM" : "não");
        
        // Posição geográfica
        printf("Posição: %d°%d'%.2f\" S, %d°%d'%.2f\" O\n", 
               posicao.latitude.graus, posicao.latitude.minutos, posicao.latitude.segundos,
               posicao.longitude.graus, posicao.longitude.minutos, posicao.longitude.segundos);
        
        // Sistema de alertas
        int alertas_ativos = 0;
        
        // Alerta de temperatura alta
        if (temp_media > limiar_temp_alta && !alerta_temp) {
            printf("⚠️ ALERTA: Temperatura acima do limite (%.2f°C)\n", limiar_temp_alta);
            alerta_temp = 1;
            alertas_ativos = 1;
        } else if (temp_media <= limiar_temp_alta && alerta_temp) {
            printf("✓ Temperatura normalizada\n");
            alerta_temp = 0;
        }
        
        // Alerta de som alto
        if (som_media > limiar_som_alto && !alerta_som) {
            printf("⚠️ ALERTA: Nível de som acima do limite (%.2f dB)\n", limiar_som_alto);
            alerta_som = 1;
            alertas_ativos = 1;
        } else if (som_media <= limiar_som_alto && alerta_som) {
            printf("✓ Nível de som normalizado\n");
            alerta_som = 0;
        }
        
        // Alerta de chama detectada
        if (chama && !alerta_chama) {
            printf("🔥 ALERTA: Chama detectada!\n");
            alerta_chama = 1;
            alertas_ativos = 1;
        } else if (!chama && alerta_chama) {
            printf("✓ Chama não mais detectada\n");
            alerta_chama = 0;
        }
        
        // Resumo de status
        if (!alertas_ativos) {
            printf("✓ Todos os sensores em níveis normais\n");
        }
        
        printf("------------------------------------\n");
        sleep_ms(AMOSTRAGEM_MS);
    }

    return 0;
}