#ifndef GRAFO_H
#define GRAFO_H


typedef struct grafo Grafo;

Grafo* criaGrafo(int nvertices, int grau_max, int eh_ponderado);
void freeGrafo(Grafo* gr);


#endif