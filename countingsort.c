#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) {
    int output[size + 1];

    // Encontrar o maior elemento do array
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Criar um array de contagem com o tamanho máximo
    int count[max + 1];

    // Inicializar todos os elementos do array de contagem com 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Contar a ocorrência de cada elemento no array
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Calcular a posição correta de cada elemento no array ordenado
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Construir o array ordenado
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copiar o array ordenado para o array original
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {9, 5, 2, 7, 1, 3, 6, 8, 4};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting: ");
    printArray(array, size);

    countingSort(array, size);

    printf("Array after sorting: ");
    printArray(array, size);

    return 0;
}
