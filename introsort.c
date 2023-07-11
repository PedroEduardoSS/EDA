#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= left && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right) {
    int pivot = array[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return (i + 1);
}

int medianOfThree(int array[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (array[mid] < array[left])
        swap(&array[left], &array[mid]);
    if (array[right] < array[left])
        swap(&array[left], &array[right]);
    if (array[right] < array[mid])
        swap(&array[mid], &array[right]);
    return array[mid];
}

void introSortRecursive(int array[], int left, int right, int depthLimit) {
    if (right - left <= 16) {
        insertionSort(array, left, right);
        return;
    }

    if (depthLimit == 0) {
        // Use Heap Sort as fallback
        // implementação do Heap Sort aqui
        return;
    }

    int pivot = medianOfThree(array, left, right);
    int partitionIndex = partition(array, left, right);

    introSortRecursive(array, left, partitionIndex - 1, depthLimit - 1);
    introSortRecursive(array, partitionIndex + 1, right, depthLimit - 1);
}

void introSort(int array[], int n) {
    int depthLimit = 2 * log(n);
    introSortRecursive(array, 0, n - 1, depthLimit);
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {9, 5, 2, 7, 1, 3, 6, 8, 4};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting: ");
    printArray(array, n);

    introSort(array, n);

    printf("Array after sorting: ");
    printArray(array, n);

    return 0;
}
