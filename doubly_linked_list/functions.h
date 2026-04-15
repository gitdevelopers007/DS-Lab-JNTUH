#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertBeginning(Node** head, int data);
void insertEnd(Node** head, int data);
void insertPosition(Node** head, int data, int position);
void deleteBeginning(Node** head);
void deleteEnd(Node** head);
void deletePosition(Node** head, int position);
void displayForward(Node* head);
void displayBackward(Node* head);

#endif
