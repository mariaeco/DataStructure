//TABELA HASH COM VETOR
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

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
    whlie(t[id] != -1){ //percorrendo ate a posicao vazia
        id = funcaoHash(id+1);
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    whlie(t[id] != -1){ //percorrendo ate a posicao vazia
        if(t[id] == chave){
            return t[id]/;
        }else{
            id = funcaoHash(id+1);
        }
    }
}

void imprimir(int t[]){
    int i;
    for(i = 0; i<TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(){
    int tabela[TAM];

    return 0;

}