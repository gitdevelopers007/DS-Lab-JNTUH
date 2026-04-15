#include "functions.h"

void menu() {
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Display Forward\n");
    printf("8. Display Backward\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

int main() {
    Node* head = NULL;
    int choice, data, pos;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(&head, data, pos);
                break;
            case 4:
                deleteBeginning(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(&head, pos);
                break;
            case 7:
                displayForward(head);
                break;
            case 8:
                displayBackward(head);
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
