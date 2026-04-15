#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data);
Node* insert(Node* node, int data);

// Recursive Traversals
void preorderRecursive(Node* root);
void inorderRecursive(Node* root);
void postorderRecursive(Node* root);

// Non-Recursive Traversals
void preorderNonRecursive(Node* root);
void inorderNonRecursive(Node* root);
void postorderNonRecursive(Node* root);

#endif
