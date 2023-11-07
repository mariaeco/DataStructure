/*
PROGRAMA: ALGORITIMOS DE ORDENACAO
AUTOR: MARIA MARCOLINA CARDOSO

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"




int main(){
    
    int choice = 0;
    int num;
    int *vetor;
    const char *caminhoDoArquivo = "num.1000.1.txt";
    
    num = contarLinhasArquivo(caminhoDoArquivo); // Obtenha o tamanho do vetor
    vetor = abrirArquivo(caminhoDoArquivo, num);



    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Ordenar por Selection Sort\n");
        printf("2 - Ordenar por Insertion Sort\n");
        printf("3 - Ordenar por Merge Sort\n");
        printf("0 - Sair\n");
   
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //CriaPilha
                selection_sort(vetor, num);
                system("pause");
                system("cls");
                break;
            case 2: //Push
                system("cls");
                break;
            case 3: //Pop
                
                system("cls");
                break;
            default:
                if(choice==0){
                exit(0);
                }
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    return 0;
}
