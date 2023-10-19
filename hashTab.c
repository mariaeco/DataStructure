//TABELA HASH COM LISTA
#include <stdio.h>
#include "hash.h"

typedef struct no{
    int chave;
    struct no *prox;
};         

typedef struct lista{
    No *inicio;
    int tam; // na propria estrutura eu aponto para alguem do mesmo tipo dela
};


void iniciaLista(Lista *L){
    L->inicio = NULL;
    L->tam = -1;
}

void insertirLista(Lista *L, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->prox = L->inicio;
        L->inicio = novo;
        L->tam++;
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}

// Função para buscar um elemento. Retorna o elemento encontrado ou zero caso contrário.
int buscar_na_lista(Lista *L, int valor){
    No *aux = L->inicio;
    while(aux && aux->chave != valor)
        aux = aux->prox;
    if(aux)
        return aux->chave;
    return 0;
}

// Procedimento para imprimir a lista recebida como parâmetro.
void imprimir_lista(Lista *L){
    No *aux = L->inicio;
    printf(" Tam: %d: ", L->tam);
    while(aux){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}