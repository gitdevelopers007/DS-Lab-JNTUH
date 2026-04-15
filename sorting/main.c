#include "functions.h"

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int original[n], arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &original[i]);

    int choice;
    while (1) {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Shell Sort\n");
        printf("2. Heap Sort\n");
        printf("3. Radix Sort\n");
        printf("4. Tree Sort\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        copyArray(original, arr, n);

        switch (choice) {
            case 1:
                shellSort(arr, n);
                printf("Sorted by Shell Sort: ");
                break;
            case 2:
                heapSort(arr, n);
                printf("Sorted by Heap Sort: ");
                break;
            case 3:
                radixSort(arr, n);
                printf("Sorted by Radix Sort: ");
                break;
            case 4:
                treeSort(arr, n);
                printf("Sorted by Tree Sort: ");
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        printArray(arr, n);
    }

    return 0;
}
