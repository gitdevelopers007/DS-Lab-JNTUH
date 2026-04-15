#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertBeginning(Node** last, int data);
void insertEnd(Node** last, int data);
void insertPosition(Node** last, int data, int position);
void deleteBeginning(Node** last);
void deleteEnd(Node** last);
void deletePosition(Node** last, int position);
void display(Node* last);

#endif
