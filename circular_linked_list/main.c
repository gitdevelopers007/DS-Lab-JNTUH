#include "functions.h"

void menu() {
    printf("\n--- Circular Linked List Menu ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Display\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

int main() {
    Node* last = NULL;
    int choice, data, pos;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(&last, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&last, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(&last, data, pos);
                break;
            case 4:
                deleteBeginning(&last);
                break;
            case 5:
                deleteEnd(&last);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(&last, pos);
                break;
            case 7:
                display(last);
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
