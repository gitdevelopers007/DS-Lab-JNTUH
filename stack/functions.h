#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Array implementation structure
typedef struct {
    int arr[MAX];
    int top;
} ArrayStack;

// ADT (Linked List) implementation structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} ADTStack;

// Array Stack functions
void initArrayStack(ArrayStack* s);
void pushArray(ArrayStack* s, int data);
int popArray(ArrayStack* s);
void displayArray(ArrayStack* s);

// ADT Stack functions
void initADTStack(ADTStack* s);
void pushADT(ADTStack* s, int data);
int popADT(ADTStack* s);
void displayADT(ADTStack* s);

#endif
