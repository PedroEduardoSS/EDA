#include <stdio.h>
#include <stdlib.h>

int binarySearch(int value, int n, int v[]) {
    int left = 0;
    int right = n - 1;
    while (left <= right){
        int middle = left + (right - left) / 2;

        if (v[middle] == value){
            return middle;
        }

        if (v[middle] > value){
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return -1;

}

int main() {
    int vetor[] = {1, 4, 7, 9, 10, 12, 15, 18};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 18;

    int indice = binarySearch(valor, tamanho, vetor);
    if (indice < tamanho && vetor[indice] == valor) {
        printf("O valor %d foi encontrado no indice %d\n", valor, indice);
    } else {
        printf("O valor %d nao foi encontrado\n", valor);
    }

    return 0;
}
