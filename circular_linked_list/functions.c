#include "functions.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(Node** last, int data) {
    Node* newNode = createNode(data);
    if (*last == NULL) {
        *last = newNode;
        (*last)->next = *last;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
    }
}

void insertEnd(Node** last, int data) {
    Node* newNode = createNode(data);
    if (*last == NULL) {
        *last = newNode;
        (*last)->next = *last;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

void insertPosition(Node** last, int data, int position) {
    if (position < 1) return;
    if (position == 1) {
        insertBeginning(last, data);
        return;
    }
    if (*last == NULL) return;
    Node* temp = (*last)->next;
    for (int i = 1; i < position - 1 && temp != *last; i++) {
        temp = temp->next;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == *last) {
        *last = newNode;
    }
}

void deleteBeginning(Node** last) {
    if (*last == NULL) return;
    Node* head = (*last)->next;
    if (head == *last) {
        free(*last);
        *last = NULL;
    } else {
        (*last)->next = head->next;
        free(head);
    }
}

void deleteEnd(Node** last) {
    if (*last == NULL) return;
    Node* head = (*last)->next;
    if (head == *last) {
        free(*last);
        *last = NULL;
    } else {
        Node* temp = head;
        while (temp->next != *last) {
            temp = temp->next;
        }
        temp->next = head;
        free(*last);
        *last = temp;
    }
}

void deletePosition(Node** last, int position) {
    if (*last == NULL || position < 1) return;
    if (position == 1) {
        deleteBeginning(last);
        return;
    }
    Node* head = (*last)->next;
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 1; i < position && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head) return; // Not found
    prev->next = temp->next;
    if (temp == *last) {
        *last = prev;
    }
    free(temp);
}

void display(Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* head = last->next;
    printf("List elements: ");
    do {
        printf("%d -> ", head->data);
        head = head->next;
    } while (head != last->next);
    printf("(circular)\n");
}
