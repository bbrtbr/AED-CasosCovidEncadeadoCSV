#ifndef LISTA_H // IF para verificar se essa estruturação ja foi implementada
#define LISTA_H

typedef struct No {
    char pais[100];
    char estado[100];
    int totalCasos;
    int totalCasosMS;
    int naoConfirmadosPorMS;
    int mortes;
    int mortesMS;
    char URL[200];
    float mortes_por_100k_habitantes;
    float totalCasos_por_100k_habitantes;
    float mortes_por_totalCasos;
    int recuperados;
    int suspeitos;
    int testes;
    float testes_por_100k_habitantes;
    int vacinados;
    float vacinados_por_100_habitantes;
    int vacinados_segunda_dose;
    float vacinados_segunda_dose_por_100_habitantes;
    int vacinados_dose_unica;
    float vacinados_dose_unica_por_100_habitantes;
    int vacinados_terceira_dose;
    float vacinados_terceira_dose_por_100_habitantes;
    char data[20];
    int novosCasos;
    int novasMortes;
    struct No* proxTotalCasos;
    struct No* proxMortes;
} No;



#endif  
