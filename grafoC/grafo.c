//GRAFO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"



struct no{ //nos da lista
    char vertice[MAX_STRING];
    struct no* prox;
};

struct grafo{
    int maxVertices;
    int nVertices;
    No** adjList;  //vetor de ponteiros para lista de adjancencias
    int **adjmatrix;
};

No* criarNo(char VERTICE[MAX_STRING]) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strncpy(novo->vertice, VERTICE, sizeof(novo->vertice)-1); // Copie o nome para a estrutura
    novo->vertice[sizeof(novo->vertice) - 1] = '\0'; // Garanta que o campo vertice seja nulo-terminado
    novo->prox = NULL;
    return novo;
};

Grafo* criaGrafo(int nvertices, char *vertices[MAX_STRING]) {
    Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
    if (gr == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    gr->maxVertices = nvertices;

    gr->adjList = (No**)malloc(nvertices * sizeof(No*));
    if (gr->adjList == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    addVertice(gr, vertices);
    // MINHA MATRIZ DE ADJACENCIAS
    int i, j;
    gr->adjmatrix = (int **)malloc(nvertices * sizeof(int *));
    for (i = 0; i < nvertices; i++) {
            gr->adjmatrix[i] = (int *)malloc(nvertices * sizeof(int));
    }
    if (gr->adjmatrix == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    
    //PREENCHENDO A MATRIZ COM ZEROS
    for(j=0; j < gr->maxVertices; j++){
        for(i=0; i < gr->maxVertices; i++){
            gr->adjmatrix[i][j] = 0;
        }
    }

    return gr;
}

void addVertice(Grafo *gr, char* nome[MAX_STRING]){
    int n;
    printf(" ----------- VERTICES  ---------------\n");
    for (n=0; n < gr->maxVertices; n++){
        printf("Vertice: %s\n",nome[n]);
        gr->adjList[n] = criarNo(nome[n]);
    }
    /* Para pedir para o usuaro digitar os nomes, etem q remover o const char *vertice da funcao
    char nome[MAX_STRING];
    while(n < gr->maxVertices){
        //printf("Digite  nome da vertice %d: ", n+1);
        scanf("%[^\n]%*c", &nome);
        gr->adjList[n] = criarNo(nome);
        n++;
    }
    */
}

void addAresta(Grafo *gr, char vert1[MAX_STRING], 
                char vert2[MAX_STRING], int dist){
    int i = findIndice(gr, vert1);
    int j = findIndice(gr, vert2);
    gr->adjmatrix[i][j] = dist;


    // Crie um novo nó para a vertice de destino (city2)
    No *novoNo = criarNo(gr->adjList[j]->vertice);

    // Obtenha o primeiro nó da lista de adjacência do vértice city1
    No *atual = gr->adjList[i];

    // Percorra a lista até encontrar o último nó
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Adicione o novo nó ao final da lista
    atual->prox = novoNo;
}

int findIndice(Grafo *gr, char nomevertice[MAX_STRING]) {
    for (int i = 0; i < gr->maxVertices; i++) {
        if (strcmp(gr->adjList[i]->vertice, nomevertice) == 0) {
            //printf("%d", i);
            return i; // Retorna o índice da vertice X
        }
    }
    return printf("\nvertice nao encontrada z \n"); // Retorna -1 se a vertice X não for encontrada
}

void printVertices(Grafo *gr){
    Grafo *aux = gr;
    printf(" ----------- LISTA DE ADJACENCIAS ---------------\n");
    for (int i = 0; i < gr->maxVertices; i++) {
        printf("%s: ",gr->adjList[i]->vertice);

        No *atual = gr->adjList[i]->prox; // Comece do primeiro nó após o vértice
        while (atual != NULL) {
            printf("%s ->", atual->vertice);
            atual = atual->prox;
        }
    printf("\n");
    }
}


void printadjMatrix(Grafo *gr){
    int i, j;
    
    printf(" ----------- MATRIZ DE ADJACENCIAS ---------------\n");
    printf("            ");
    for (i = 0; i < gr->maxVertices; i++) {
        printf("%-15s", gr->adjList[i]);
    }
    printf("\n");
    
    for(j=0; j < gr->maxVertices; j++){
        printf("%-15s", gr->adjList[j]);
        for(i=0; i < gr->maxVertices; i++){
            printf("%-15d", gr->adjmatrix[i][j]);
        }
        printf("\n");
    }
}





