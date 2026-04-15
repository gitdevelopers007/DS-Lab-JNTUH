#include "functions.h"

void menu() {
    printf("\n--- Stack Menu ---\n");
    printf("1. Push (Array)\n");
    printf("2. Pop (Array)\n");
    printf("3. Display (Array)\n");
    printf("4. Push (ADT)\n");
    printf("5. Pop (ADT)\n");
    printf("6. Display (ADT)\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

int main() {
    ArrayStack as;
    ADTStack ads;
    initArrayStack(&as);
    initADTStack(&ads);

    int choice, data;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                pushArray(&as, data);
                break;
            case 2:
                data = popArray(&as);
                if (data != -1) printf("Popped: %d\n", data);
                break;
            case 3:
                displayArray(&as);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                pushADT(&ads, data);
                break;
            case 5:
                data = popADT(&ads);
                if (data != -1) printf("Popped: %d\n", data);
                break;
            case 6:
                displayADT(&ads);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
