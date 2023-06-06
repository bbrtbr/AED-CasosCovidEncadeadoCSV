#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    void *dados;
    struct no *anterior;
    struct no *proximo;
} No;

typedef struct {
    No *primeiro;
    No *ultimo;
    int tamanho;
} Lista;

Lista* criarLista();
void destruirLista(Lista *lista);
void inserirElemento(Lista *lista, void *dados, int tamanhoDados, int (*comparar)(void*, void*));
void imprimirLista(Lista *lista, void (*imprimir)(void*));

#endif
