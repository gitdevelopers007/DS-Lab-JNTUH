#include "functions.h"

// --- Array Stack Implementation ---
void initArrayStack(ArrayStack* s) {
    s->top = -1;
}

void pushArray(ArrayStack* s, int data) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = data;
    printf("%d pushed to Array Stack.\n", data);
}

int popArray(ArrayStack* s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void displayArray(ArrayStack* s) {
    if (s->top == -1) {
        printf("Array Stack is empty.\n");
        return;
    }
    printf("Array Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// --- ADT (Linked List) Stack Implementation ---
void initADTStack(ADTStack* s) {
    s->top = NULL;
}

void pushADT(ADTStack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushed to ADT Stack.\n", data);
}

int popADT(ADTStack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

void displayADT(ADTStack* s) {
    if (s->top == NULL) {
        printf("ADT Stack is empty.\n");
        return;
    }
    printf("ADT Stack: ");
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
