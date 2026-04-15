#include "functions.h"

void menu() {
    printf("\n--- Queue Menu ---\n");
    printf("1. Enqueue (Array)\n");
    printf("2. Dequeue (Array)\n");
    printf("3. Display (Array)\n");
    printf("4. Enqueue (ADT)\n");
    printf("5. Dequeue (ADT)\n");
    printf("6. Display (ADT)\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

int main() {
    ArrayQueue aq;
    ADTQueue adq;
    initArrayQueue(&aq);
    initADTQueue(&adq);

    int choice, data;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueueArray(&aq, data);
                break;
            case 2:
                data = dequeueArray(&aq);
                if (data != -1) printf("Dequeued: %d\n", data);
                break;
            case 3:
                displayArray(&aq);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueueADT(&adq, data);
                break;
            case 5:
                data = dequeueADT(&adq);
                if (data != -1) printf("Dequeued: %d\n", data);
                break;
            case 6:
                displayADT(&adq);
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
