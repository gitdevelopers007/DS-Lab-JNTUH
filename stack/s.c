#include <stdio.h>
#define MAX 100
int stackArray[MAX];
int topArray = -1;
void pushArray(int value) {
 if (topArray == MAX - 1) {
 printf("Stack overflow\n");
 return;
 }
 topArray++;
 stackArray[topArray] = value;
}
void popArray() {
 if (topArray == -1) {
 printf("Stack underflow\n");
 return;
 }
 printf("Deleted element: %d\n", stackArray[topArray]);
 topArray--;
}
void displayArray() {
 int i;
 if (topArray == -1) {
 printf("Stack is empty\n");
 return;
 }
 printf("Stack using array: ");
 for (i = topArray; i >= 0; i--) {
 printf("%d ", stackArray[i]);
 }
 printf("\n");
}
struct StackADT {
 int items[MAX];
 int top;
};
void initStack(struct StackADT *s) {
 s->top = -1;
}
void pushADT(struct StackADT *s, int value) {
 if (s->top == MAX - 1) {
 printf("Stack overflow\n");
 return;
 }
 s->top++;
 s->items[s->top] = value;
}
void popADT(struct StackADT *s) {
 if (s->top == -1) {
 printf("Stack underflow\n");
 return;
 }
 printf("Deleted element: %d\n", s->items[s->top]);
 s->top--;
}
void displayADT(struct StackADT s) {
 int i;
 if (s.top == -1) {
 printf("Stack is empty\n");
 return;
 }
 printf("Stack using ADT: ");for (i = s.top; i >= 0; i--) {
 printf("%d ", s.items[i]);
 }
 printf("\n");
}
int main() {
 struct StackADT stackADT;
 int choice, value;
 initStack(&stackADT);
 do {
 printf("\nStack Operations\n");
 printf("1. Push using array\n");
 printf("2. Pop using array\n");
 printf("3. Display array stack\n");
 printf("4. Push using ADT\n");
 printf("5. Pop using ADT\n");
 printf("6. Display ADT stack\n");
 printf("7. Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value: ");
 scanf("%d", &value);
 pushArray(value);
 break;
 case 2:
 popArray();
 break;
 case 3:
 displayArray();
 break;
 case 4:
 printf("Enter value: ");
 scanf("%d", &value);
 pushADT(&stackADT, value);
 break;
 case 5:
 popADT(&stackADT);
 break;
 case 6:
 displayADT(stackADT);
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


//Sample Output:
Stack Operations
1. Push using array
2. Pop using array
3. Display array stack
4. Push using ADT
5. Pop using ADT
6. Display ADT stack
7. Exit
Enter choice: 1
Enter value: 10
Enter choice: 1
Enter value: 20
Enter choice: 3
Stack using array: 20 10//