#ifndef GRAFO_H
#define GRAFO_H

#define MAX_STRING 15

typedef struct no No; //lista de adjacencias
typedef struct grafo Grafo;

No* criarNo(char VERTICE[MAX_STRING]);
Grafo* criaGrafo(int nvertices, char *vertices[MAX_STRING]);
void addVertice(Grafo *gr, char *nome[MAX_STRING]);
void addAresta(Grafo *gr, char vert1[MAX_STRING], char vert2[MAX_STRING], int dist);
void printadjMatrix(Grafo *gr);
void printVertices(Grafo *gr);
int findIndice(Grafo *gr, char nomevertice[MAX_STRING]);
//void BFS(Grafo* gr, int vertice, EstadoVertice *estado);
//void DFS(Grafo* gr, char* origem);

#endif