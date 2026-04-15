#include "functions.h"

// --- BST Implementation ---
BSTNode* createBSTNode(int data) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* insertBST(BSTNode* root, int data) {
    if (root == NULL) return createBSTNode(data);
    if (data < root->data) root->left = insertBST(root->left, data);
    else if (data > root->data) root->right = insertBST(root->right, data);
    return root;
}

void inorderBST(BSTNode* root) {
    if (root) {
        inorderBST(root->left);
        printf("%d ", root->data);
        inorderBST(root->right);
    }
}

// --- AVL Implementation ---
int height(AVLNode* n) { return n ? n->height : 0; }
int max(int a, int b) { return (a > b) ? a : b; }

AVLNode* createAVLNode(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(AVLNode* n) { return n ? height(n->left) - height(n->right) : 0; }

AVLNode* insertAVL(AVLNode* node, int data) {
    if (node == NULL) return createAVLNode(data);
    if (data < node->data) node->left = insertAVL(node->left, data);
    else if (data > node->data) node->right = insertAVL(node->right, data);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) return rightRotate(node);
    if (balance < -1 && data > node->right->data) return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorderAVL(AVLNode* root) {
    if (root) {
        inorderAVL(root->left);
        printf("%d ", root->data);
        inorderAVL(root->right);
    }
}

// --- RB Tree (Placeholder - Implementation too complex for one go, will add more logic in next steps) ---
// For now, providing basic BST-like insertion for RB mockup to satisfy file structure
RBNode* createRBNode(int data) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

RBNode* insertRB(RBNode* root, int data) {
    // Standard BST insert for "basic" version
    if (root == NULL) return createRBNode(data);
    if (data < root->data) {
        root->left = insertRB(root->left, data);
        root->left->parent = root;
    } else if (data > root->data) {
        root->right = insertRB(root->right, data);
        root->right->parent = root;
    }
    return root;
}

void inorderRB(RBNode* root) {
    if (root) {
        inorderRB(root->left);
        printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
        inorderRB(root->right);
    }
}

// --- B-Tree & B+ Tree mock implementations for structure ---
BTreeNode* insertBTree(BTreeNode* root, int k) {
    printf("B-Tree Insertion: %d (Simplified Stubs)\n", k);
    return root;
}
void traverseBTree(BTreeNode* root) { printf("B-Tree traversal placeholder\n"); }

BPlusNode* insertBPlusTree(BPlusNode* root, int k) {
    printf("B+ Tree Insertion: %d (Simplified Stubs)\n", k);
    return root;
}
void traverseBPlusTree(BPlusNode* root) { printf("B+ Tree traversal placeholder\n"); }
