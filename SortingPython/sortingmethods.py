import time

MAX_SIZE = 1000005  # Tamanho máximo do vetor, ajuste conforme necessário

def selection_sort(v):
    n = len(v)
    for i in range(n - 1):
        my_id = i
        for j in range(i + 1, n):
            if v[my_id] > v[j]:
                my_id = j
        if i != my_id:
            v[i], v[my_id] = v[my_id], v[i]

def insertion_sort(v):
    n = len(v)
    for i in range(1, n):
        aux = v[i]
        indice = i 
        while indice > 0 and aux < v[indice-1]:
            v[indice] = v[indice-1]
            indice -= 1
        v[indice] = aux

def merge_sort(v):
    def merge(v, inicio, meio, fim):
        aux = [0] * len(v)
        i = inicio
        j = meio + 1
        print("\n\n Meio:", j, "\n\n")
        k = inicio

        while i <= meio and j <= fim:
            if v[i] < v[j]:
                aux[k] = v[i]
                i += 1
            else:
                aux[k] = v[j]
                j += 1
            k += 1

        while i <= meio:
            aux[k] = v[i]
            i += 1
            k += 1

        while j <= fim:
            aux[k] = v[j]
            j += 1
            k += 1

        for i in range(inicio, fim + 1):
            v[i] = aux[i]

    def merge_sort_helper(v, inicio, fim):
        if inicio < fim:
            meio = (inicio + (fim - 1)) // 2
            merge_sort_helper(v, inicio, meio)
            merge_sort_helper(v, meio + 1, fim)
            merge(v, inicio, meio, fim)

    merge_sort_helper(v, 0, len(v) - 1)

def imprimir(v):
    print("\n\n\n ------------------------ VETOR ORDENADO ------------------------------------\n")
    for num in v:
        print(num, end=" ")
    print("\n\n")

def contar_linhas_arquivo(nome_arquivo):
    with open(nome_arquivo, "r") as arquivo:
        contador = sum(1 for linha in arquivo)
    return contador

def abrir_arquivo(nome_arquivo):
    with open(nome_arquivo, "r") as arquivo:
        linhas = arquivo.readlines()
        v = [int(linha.strip()) for linha in linhas]
    print("\nTamanho do arquivo:", len(v))
    return v

