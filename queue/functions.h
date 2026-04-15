#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Array implementation structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} ArrayQueue;

// ADT (Linked List) implementation structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} ADTQueue;

// Array Queue functions
void initArrayQueue(ArrayQueue* q);
void enqueueArray(ArrayQueue* q, int data);
int dequeueArray(ArrayQueue* q);
void displayArray(ArrayQueue* q);

// ADT Queue functions
void initADTQueue(ADTQueue* q);
void enqueueADT(ADTQueue* q, int data);
int dequeueADT(ADTQueue* q);
void displayADT(ADTQueue* q);

#endif
