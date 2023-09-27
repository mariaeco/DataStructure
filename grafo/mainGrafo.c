#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main(){

    Grafo *gr;

    gr = criaGrafo(10, 7, 0);
    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 1, 3, 0, 0);
    printf("todo ok!\n");


    free(gr);
    system("pause");
    return 0;
}