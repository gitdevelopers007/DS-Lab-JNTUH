#include <stdio.h>
#define MAX 100
int queueArray[MAX];
int frontArray = -1;
int rearArray = -1;
void enqueueArray(int value) {
 if (rearArray == MAX - 1) {
 printf("Queue overflow\n");
 return;
 }
 if (frontArray == -1) {
 frontArray = 0;
 }
 rearArray++;
 queueArray[rearArray] = value;
}
void dequeueArray() {
 if (frontArray == -1 || frontArray > rearArray) {
 printf("Queue underflow\n");
 return;
 }
 printf("Deleted element: %d\n", queueArray[frontArray]);
 frontArray++;
 if (frontArray > rearArray) {
 frontArray = rearArray = -1;
 }
}
void displayArray() {
 int i;
 if (frontArray == -1) {
 printf("Queue is empty\n");
 return;
 }
 printf("Queue using array: ");
 for (i = frontArray; i <= rearArray; i++) {
 printf("%d ", queueArray[i]);
 }
 printf("\n");
}
struct QueueADT {
 int items[MAX];
 int front;
 int rear;
};
void initQueue(struct QueueADT *q) {
 q->front = -1;
 q->rear = -1;
}
void enqueueADT(struct QueueADT *q, int value) {
 if (q->rear == MAX - 1) {
 printf("Queue overflow\n");
 return;
 }
 if (q->front == -1) {
 q->front = 0;
 }
 q->rear++;
 q->items[q->rear] = value;
}
void dequeueADT(struct QueueADT *q) {
 if (q->front == -1 || q->front > q->rear) {
 printf("Queue underflow\n");
 return;}
 printf("Deleted element: %d\n", q->items[q->front]);
 q->front++;
 if (q->front > q->rear) {
 q->front = q->rear = -1;
 }
}
void displayADT(struct QueueADT q) {
 int i;
 if (q.front == -1) {
 printf("Queue is empty\n");
 return;
 }
 printf("Queue using ADT: ");
 for (i = q.front; i <= q.rear; i++) {
 printf("%d ", q.items[i]);
 }
 printf("\n");
}
int main() {
 struct QueueADT queueADT;
 int choice, value;
 initQueue(&queueADT);
 do {
 printf("\nQueue Operations\n");
 printf("1. Enqueue using array\n");
 printf("2. Dequeue using array\n");
 printf("3. Display array queue\n");
 printf("4. Enqueue using ADT\n");
 printf("5. Dequeue using ADT\n");
 printf("6. Display ADT queue\n");
 printf("7. Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value: ");
 scanf("%d", &value);
 enqueueArray(value);
 break;
 case 2:
 dequeueArray();
 break;
 case 3:
 displayArray();
 break;
 case 4:
 printf("Enter value: ");
 scanf("%d", &value);
 enqueueADT(&queueADT, value);
 break;
 case 5:
 dequeueADT(&queueADT);
 break;
 case 6:
 displayADT(queueADT);
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