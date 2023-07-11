#include <stdio.h>

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) {
        if (arr[mid] > arr[high]) {
            return mid;
        } else if (arr[low] > arr[high]) {
            return high;
        } else {
            return low;
        }
    } else {
        if (arr[low] > arr[high]) {
            return low;
        } else if (arr[mid] > arr[high]) {
            return high;
        } else {
            return mid;
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // escolhe o pivô como a mediana de três
        int pivotIndex = medianOfThree(arr, low, high);
        int pivot = arr[pivotIndex];

        // coloca o pivô no final do array
        int temp = arr[pivotIndex];
        arr[pivotIndex] = arr[high];
        arr[high] = temp;

        // realiza a partição
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // coloca o pivô em sua posição correta
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // chama recursivamente o Quick Sort para as duas metades do array
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
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
