#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node *next;
};
struct Node *createNode(int data) {
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}
void createList(struct Node **head, int n) {
 int value, i;
 struct Node *temp, *newNode;
 for (i = 0; i < n; i++) {
 printf("Enter value %d: ", i + 1);
 scanf("%d", &value);
 newNode = createNode(value);
 if (*head == NULL) {
 *head = newNode;
 } else {
 temp = *head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
 }
}
void insertAtBeginning(struct Node **head, int value) {
 struct Node *newNode = createNode(value);
 newNode->next = *head;
 *head = newNode;
}
void insertAtEnd(struct Node **head, int value) {
 struct Node *newNode = createNode(value);
 struct Node *temp;
 if (*head == NULL) {
 *head = newNode;
 return;
 }
 temp = *head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;}
void deleteFromBeginning(struct Node **head) {
 struct Node *temp;
 if (*head == NULL) {
 printf("List is empty\n");
 return;
 }
 temp = *head;
 *head = (*head)->next;
 free(temp);
}
void deleteFromEnd(struct Node **head) {
 struct Node *temp, *prev;
 if (*head == NULL) {
 printf("List is empty\n");
 return;
 }
 if ((*head)->next == NULL) {
 free(*head);
 *head = NULL;
 return;
 }
 temp = *head;
 while (temp->next != NULL) {
 prev = temp;
 temp = temp->next;
 }
 prev->next = NULL;
 free(temp);
}
void traverseList(struct Node *head) {
 if (head == NULL) {
 printf("List is empty\n");
 return;
 }
 printf("List: ");
 while (head != NULL) {
 printf("%d ", head->data);
 head = head->next;
 }
 printf("\n");
}
int main() {
 struct Node *head = NULL;
 int choice, n, value;
 do {
 printf("\nSingly Linked List\n");
 printf("1. Create\n");
 printf("2. Insert at beginning\n");
 printf("3. Insert at end\n");
 printf("4. Delete from beginning\n");
 printf("5. Delete from end\n");
 printf("6. Traverse\n");
 printf("7. Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("How many nodes? ");
 scanf("%d", &n);
 createList(&head, n);
 break;
 case 2:
 printf("Enter value: ");
 scanf("%d", &value);
 insertAtBeginning(&head, value);
 break;case 3:
 printf("Enter value: ");
 scanf("%d", &value);
 insertAtEnd(&head, value);
 break;
 case 4:
 deleteFromBeginning(&head);
 break;
 case 5:
 deleteFromEnd(&head);
 break;
 case 6:
 traverseList(head);
 break;
 case 7:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice\n");
 }
 } while (choice != 7);
 return 0;
}