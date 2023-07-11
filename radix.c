#include <stdio.h>

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

void countSort(int array[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

void radixSort(int array[], int n) {
    int max = getMax(array, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(array, n, exp);
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {162, 415, 248, 835, 623};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting: ");
    printArray(array, n);

    radixSort(array, n);

    printf("Array after sorting: ");
    printArray(array, n);

    return 0;
}
