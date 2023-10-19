#ifndef HASHV_H
#define HASHV_H

#define TAM 10


void inicializaTabela(int t[]);
int funcaoHash(int chave);
void inserir(int t[], int valor);
int busca(int t[], int chave);
void imprimir(int t[]);

#endif // 