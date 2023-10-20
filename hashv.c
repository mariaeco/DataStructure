//TABELA HASH COM VETOR
#include <stdio.h>
#include <stdlib.h>
#include "hashv.h"


void inicializaTabela(int t[]){
    int i;
    for(i = 0; i< TAM; i++){
        t[i] = -1;
    }
}

int funcaoHash(int chave){
    return chave%TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != -1){ //percorrendo ate a posicao vazia
        id = funcaoHash(id+1);
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    while(t[id] != -1){ //percorrendo ate a posicao vazia
        if(t[id] == chave){
            return t[id];
        }else{
            id = funcaoHash(id+1);
        }
    }
    return 0;
}

void imprimir(int t[]){
    int i;
    for(i = 0; i<TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

