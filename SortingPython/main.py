from sortingmethods import selection_sort,insertion_sort,merge_sort,imprimir,contar_linhas_arquivo,abrir_arquivo
import time
if __name__ == "__main__":
    choice = -1
    inicio, fim = 0, 0
    caminho_do_arquivo = "teste2.txt"  # "num.1000.2.in"
    num = contar_linhas_arquivo(caminho_do_arquivo)

    while choice != 0:
        print("MEU MENU")
        print("1 - Ordenar por Selection Sort")
        print("2 - Ordenar por Insertion Sort")
        print("3 - Ordenar por Merge Sort")
        print("4 - Imprimir tempos")
        print("0 - Sair")

        choice = int(input("Escolha uma opção: "))
        if choice == 1:
            vetor = abrir_arquivo(caminho_do_arquivo)
            start = time.time()
            selection_sort(vetor)
            imprimir(vetor)
            end = time.time()
            timeS = end - start
            print(f"\n\nTempo gasto: {timeS}\n\n")
        elif choice == 2:
            vetor = abrir_arquivo(caminho_do_arquivo)
            start = time.time()
            insertion_sort(vetor)
            imprimir(vetor)
            end = time.time()
            timeI = end - start
            print(f"\n\nTempo gasto: {timeI}\n\n")
        elif choice == 3:
            vetor = abrir_arquivo(caminho_do_arquivo)
            inicio, fim = 0, len(vetor) - 1
            start = time.time()
            merge_sort(vetor)
            imprimir(vetor)
            end = time.time()
            timeM = end - start
            print(f"\n\nTempo gasto: {timeM}\n\n")
        elif choice == 4:
            print("\n\nRun Time:")
            print(f"\tSelection Sort: {timeS}")
            print(f"\tInsertion Sort: {timeI}")
            print(f"\tMerge Sort:     {timeM}\n\n")
        elif choice == 0:
            break
        else:
            print("Digite uma opção válida!")


