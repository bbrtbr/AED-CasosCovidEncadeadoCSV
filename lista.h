#ifndef LISTA_H // verificar se o arquivo ja foi implementado
#define LISTA_H

typedef struct no {
    void *dados;
    struct no *anterior;
    struct no *proximo;
} No; // Genérico

typedef struct {
    No *primeiro;
    No *ultimo;
    int tamanho;
} Lista; // Nó descritor

Lista* criarLista();
void destruirLista(Lista *lista);
void inserirElemento(Lista *lista, void *dados, int tamanhoDados, int (*comparar)(void*, void*));
void imprimirLista(Lista *lista, void (*imprimir)(void*));

#endif
