#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

// --- Binary Search Tree (BST) ---
typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} BSTNode;

BSTNode* insertBST(BSTNode* root, int data);
void inorderBST(BSTNode* root);

// --- AVL Tree ---
typedef struct AVLNode {
    int data, height;
    struct AVLNode *left, *right;
} AVLNode;

AVLNode* insertAVL(AVLNode* root, int data);
void inorderAVL(AVLNode* root);

// --- Red-Black Tree (Simplified) ---
typedef enum { RED, BLACK } Color;
typedef struct RBNode {
    int data;
    Color color;
    struct RBNode *left, *right, *parent;
} RBNode;

RBNode* insertRB(RBNode* root, int data);
void inorderRB(RBNode* root);

// --- B-Tree (Simplified, Order 3) ---
#define MAX_KEYS 3
typedef struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode *children[MAX_KEYS + 1];
    int n; // current number of keys
    int leaf; // true if leaf
} BTreeNode;

BTreeNode* insertBTree(BTreeNode* root, int k);
void traverseBTree(BTreeNode* root);

// --- B+ Tree (Simplified) ---
typedef struct BPlusNode {
    int *keys;
    struct BPlusNode **children;
    struct BPlusNode *next; // for leaf chain
    int n, leaf;
} BPlusNode;

BPlusNode* insertBPlusTree(BPlusNode* root, int k);
void traverseBPlusTree(BPlusNode* root);

#endif
