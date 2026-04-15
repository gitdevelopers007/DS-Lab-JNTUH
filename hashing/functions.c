#include "functions.h"

// --- Hash Functions ---

// 1. Division Method
int hashDivision(int key) {
    return key % TABLE_SIZE;
}

// 2. Multiplication Method
int hashMultiplication(int key) {
    double A = 0.618033; // Fractional part of (sqrt(5)-1)/2
    return (int)(TABLE_SIZE * (key * A - (int)(key * A)));
}

// 3. Mid-Square Method
int hashMidSquare(int key) {
    long square = (long)key * key;
    // Extract middle digits (simplified for demonstration)
    int mid = (square / 10) % 100; 
    return mid % TABLE_SIZE;
}

// 4. Folding Method
int hashFolding(int key) {
    int sum = 0;
    int temp = key;
    while (temp > 0) {
        sum += temp % 100; // Fold by 2 digits
        temp /= 100;
    }
    return sum % TABLE_SIZE;
}

// --- Table Operations ---

void insert(int table[], int key, int (*hashFunc)(int)) {
    int index = hashFunc(key);
    int originalIndex = index;
    
    // Linear Probing for collision handling
    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash Table is full!\n");
            return;
        }
    }
    table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void displayTable(int table[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1) printf("[%d]: EMPTY\n", i);
        else printf("[%d]: %d\n", i, table[i]);
    }
}
