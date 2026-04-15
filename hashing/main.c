#include "functions.h"

int main() {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = -1;

    int choice, key, methodChoice;
    int (*selectedHash)(int) = NULL;

    printf("Select Hashing Method for this session:\n");
    printf("1. Division Method\n");
    printf("2. Multiplication Method\n");
    printf("3. Mid-Square Method\n");
    printf("4. Folding Method\n");
    printf("Enter choice: ");
    scanf("%d", &methodChoice);

    switch (methodChoice) {
        case 1: selectedHash = hashDivision; break;
        case 2: selectedHash = hashMultiplication; break;
        case 3: selectedHash = hashMidSquare; break;
        case 4: selectedHash = hashFolding; break;
        default: printf("Invalid choice, using Division Method.\n"); selectedHash = hashDivision;
    }

    while (1) {
        printf("\n--- Hashing Menu ---\n");
        printf("1. Insert Key\n");
        printf("2. Display Table\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(table, key, selectedHash);
                break;
            case 2:
                displayTable(table);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
