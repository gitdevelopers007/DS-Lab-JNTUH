#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10

void displayTable(int table[]);
int hashDivision(int key);
int hashMultiplication(int key);
int hashMidSquare(int key);
int hashFolding(int key);

void insert(int table[], int key, int (*hashFunc)(int));

#endif
