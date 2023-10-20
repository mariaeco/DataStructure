//MAIN
#include <stdio.h>
#include <stdlib.h>
#include "hashv.h"


int main(){
    int op;
    int valor, retorno;
    int tabela[TAM];


    do{
        printf("\n\t 0 - Sair");
        printf("\n\t 1 - Inserir");
        printf("\n\t 2 - Buscar");
        printf("\n\t 3 - Imprimir\n");
        scanf("%d", &op);
        system("cls");

        switch (op){
            case 1:
                printf("\tQual valor deseja inserir? ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("\tQual valor deseja buscar? ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                if(retorno != 0){
                    printf("\nValor encontrado");
                }else{
                    printf("\nValor nao encontrado.");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while(op != 0);

    return 0;

}