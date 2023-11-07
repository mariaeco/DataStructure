#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int contarLinhasArquivo(const char* nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        exit(1);
    }
    int contador = 0;
    char linha[1000]; // Tamanho arbitrário para uma linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }

    fclose(arquivo);
    return contador;
}

int* abrirArquivo(const char* nomeArquivo, int nlinhas){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        exit(1);
    }
    //sabendo o tamanho do arquivo para poder alocar memora
    
    //alocando um vetor do tamanho do arquivo
    int *v = (int*)malloc(nlinhas * sizeof(int)); // Aloca memória para o vetor
    if (v == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        exit(1);
    }
    
    rewind(arquivo);// preciso retornar ao inicio do arquivo
    int n = 0;
    char linha[1000]; 
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        v[n] = atoi(linha);
        //printf("%d ", v[n]);
        n++;
    }
    printf("\n\ncontador 2: %d\n", n);

    fclose(arquivo);
    return v;
}
