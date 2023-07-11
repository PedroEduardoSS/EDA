#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // escolhe o �ltimo elemento como piv�
    int i = (low - 1); // �ndice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // se o elemento atual for menor ou igual ao piv�
        if (arr[j] <= pivot) {
            i++; // incrementa o �ndice do menor elemento
            // troca arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // troca arr[i+1] e arr[high] (piv�)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1); // retorna o �ndice do piv�
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // obt�m o �ndice do piv� ap�s a parti��o
        int pi = partition(arr, low, high);

        // ordena os elementos antes e depois do piv�
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {25, 11, 12, 64, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: ");
    printArray(arr, n);

    return 0;
}
