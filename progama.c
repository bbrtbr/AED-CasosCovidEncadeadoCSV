#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "lista.c"

typedef struct {
    char country[100];
    char state[100];
    int totalCases;
    int totalCasesMS;
    int notConfirmedByMS;
    int deaths;
    int deathsMS;
} Dados;

int compararMortes(void *dados1, void *dados2) {
    Dados *d1 = (Dados*)dados1; // conversão de tipo
    Dados *d2 = (Dados*)dados2;
    return d1->deaths - d2->deaths;
}

void imprimirDados(void *dados) {
    Dados *d = (Dados*)dados;
    printf("Country: %s\n", d->country);
    printf("State: %s\n", d->state);
    printf("Total Deaths: %d\n", d->deaths);
}

No* buscarPorEstado(Lista *lista, char estado[100]) {
  No *atual = lista->primeiro;

  while(atual != NULL){
    Dados *d = (Dados*) atual->dados;

    if (strcmp(estado, d->state) == 0){
      return atual;
    }
    
    atual = atual->proximo;
  }

  return NULL;
}

No* buscarMaisCasos(Lista *lista) {
  return lista->primeiro;
}

No* buscarMenosCasos(Lista *lista) {
  return lista->ultimo;
}

int main() {
    Lista *lista = criarLista();

    FILE *arquivo = fopen("../dados.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    char linha[1000];
    fgets(linha, sizeof(linha), arquivo);  //ignorar a primeira linha do arquivo "dados"

    while (fgets(linha, sizeof(linha), arquivo)) {
        Dados *d = (Dados*)malloc(sizeof(Dados));

        char *token = strtok(linha, ",");
        strcpy(d->country, token);

        token = strtok(NULL, ",");
        strcpy(d->state, token);

        token = strtok(NULL, ",");
        d->totalCases = atoi(token);

        token = strtok(NULL, ",");
        d->totalCasesMS = atoi(token);

        token = strtok(NULL, ",");
        d->notConfirmedByMS = atoi(token);

        token = strtok(NULL, ",");
        d->deaths = atoi(token);

        token = strtok(NULL, ",");
        d->deathsMS = atoi(token);

        inserirElemento(lista, d, sizeof(Dados), compararMortes);
    }

    fclose(arquivo);

    imprimirLista(lista, imprimirDados);

    //destruirLista(lista);

    return 0;
}
