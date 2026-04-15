#include "functions.h"

// --- Array Queue Implementation ---
void initArrayQueue(ArrayQueue* q) {
    q->front = -1;
    q->rear = -1;
}

void enqueueArray(ArrayQueue* q, int data) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++(q->rear)] = data;
    printf("%d enqueued to Array Queue.\n", data);
}

int dequeueArray(ArrayQueue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int data = q->arr[q->front++];
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return data;
}

void displayArray(ArrayQueue* q) {
    if (q->front == -1) {
        printf("Array Queue is empty.\n");
        return;
    }
    printf("Array Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// --- ADT (Linked List) Queue Implementation ---
void initADTQueue(ADTQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueueADT(ADTQueue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to ADT Queue.\n", data);
}

int dequeueADT(ADTQueue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

void displayADT(ADTQueue* q) {
    if (q->front == NULL) {
        printf("ADT Queue is empty.\n");
        return;
    }
    printf("ADT Queue: ");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
