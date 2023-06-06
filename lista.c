#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}

void destruirLista(Lista *lista) {
    No *atual = lista->primeiro;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual->dados);
        free(atual);
        atual = proximo;
    }
    free(lista);
}

void inserirElemento(Lista *lista, void *dados, int tamanhoDados, int (*comparar)(void*, void*)) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->dados = malloc(tamanhoDados);
    memcpy(novoNo->dados, dados, tamanhoDados); // para copiar uma area de memoria para a outra
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if (lista->primeiro == NULL) {
        lista->primeiro = novoNo;
        lista->ultimo = novoNo;
    } else {
        No *atual = lista->primeiro;
        while (atual != NULL && comparar(atual->dados, dados) < 0) {
            atual = atual->proximo;
        }
        if (atual == NULL) {
            novoNo->anterior = lista->ultimo;
            lista->ultimo->proximo = novoNo;
            lista->ultimo = novoNo;
        } else {
            novoNo->anterior = atual->anterior;
            novoNo->proximo = atual;
            if (atual->anterior != NULL) {
                atual->anterior->proximo = novoNo;
            } else {
                lista->primeiro = novoNo;
            }
            atual->anterior = novoNo;
        }
    }
    lista->tamanho++;
}

void imprimirLista(Lista *lista, void (*imprimir)(void*)) {
    No *atual = lista->primeiro;
    while (atual != NULL) {
        imprimir(atual->dados);
        atual = atual->proximo;
    }
}
