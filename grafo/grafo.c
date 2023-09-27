#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo{
    int ponderado;
    int nvertices;
    int grau_max;
    int **arestas; //matriz com as conexoes
    float **pesos;
    int* grau;
};


Grafo* criaGrafo(int nvert, int grau_max, int pond){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL){
        int i;
        gr->nvertices = nvert;
        gr->grau_max = grau_max;
        gr->ponderado = (pond != 0)?1:0;

        gr->grau = (int*)calloc(nvert, sizeof(int));// inicia cada vertice com grau 0
        gr->arestas = (int**) malloc(nvert*sizeof(int*));//criandoa matriz de conexoes

        for (i=0; i<nvert; i++){
            gr->arestas[i] = (int*) malloc(grau_max*sizeof(int));
            if(gr->ponderado){
                gr->pesos = (float**)malloc(nvert*sizeof(float*));            
                for (i=0; i<nvert; i++){
                    gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));       
                }
            }
        }
        return gr;
    }
}

void freeGrafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i < gr->nvertices; i++){
            free(gr->arestas[i]);
        }
        
        free(gr->arestas);

        if(gr->ponderado){
            for(i=0; i < gr->nvertices; i++){
                free(gr->pesos[i]);
            }
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int digrafo, float peso){
    if(gr == NULL){
        return 0;    
    }
    if(orig < 0 || orig >= gr->nvertices){ //verifica se existe a origem
        return 0;
    }
    if(dest < 0 || dest >= gr->nvertices){//verifica se existe o destino
        return 0;
    }

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->ponderado){
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;
    }

    if(digrafo == 0){//insere aresta se nao for digrafo
        insereAresta(gr, dest, orig, 1, peso);
    }
    return 1;
}

