// FILA DINAMICA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "No.h"



struct no{
    char vertice[MAX_STRING];
    struct no *proximo;
};

struct fila{
    No *inicio;
    No *fim;
    int tam;
};

Fila* criarFila(Fila *fila){
    
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
    
    return fila;
}

Fila* inserir(Fila *fila, char vert[MAX_STRING]){
    No *novo = (No*)malloc(sizeof(No));
    size_t max_size = sizeof(novo->vertice) - 1;
    size_t vert_size = strlen(vert);
    printf("teste");

    if(novo != NULL){
        strncpy(novo->vertice, vert, sizeof(novo->vertice)-1); // Copia a string vert para novo->vertice
        novo->vertice[sizeof(novo->vertice) - 1] = '\0'; // Garante que novo->vertice seja terminado com '\0'
        novo->proximo = NULL;

        if(fila->inicio == NULL){ //inserçao do meu primeiro no
            fila->inicio = novo;
            fila->fim = novo;
        }else{
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }else{
        printf("Memoria nao alocada\n\n");
    }
    return fila;
}

No* remover(Fila *fila){
    No *remover = NULL;

    if(fila->inicio){
        remover = fila->inicio;
        fila->inicio = remover->proximo;
        fila->tam--;
    }else{
        printf("\tFila vazia\n");
    }
    return remover;
}

void imprimirFila(Fila *fila){
    No *aux;

    aux = fila->inicio;
    printf("-------------- Fila ----------------\n");
    while(aux){
        printf("%s -> ", aux->vertice);
        aux = aux->proximo;
    }
    printf("FIM");
    printf("\n-------------- Fim da Fila ----------------\n");
    printf("Tamanho da fila: %d\n", fila->tam);
}
      