#include "functions.h"

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

// --- Recursive ---
void preorderRecursive(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void inorderRecursive(Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

void postorderRecursive(Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// --- Stack for Non-Recursive ---
typedef struct Stack {
    Node* data[100];
    int top;
} Stack;

void push(Stack* s, Node* node) {
    if (node != NULL) s->data[++(s->top)] = node;
}

Node* pop(Stack* s) {
    if (s->top == -1) return NULL;
    return s->data[(s->top)--];
}

// --- Non-Recursive ---
void preorderNonRecursive(Node* root) {
    if (root == NULL) return;
    Stack s; s.top = -1;
    push(&s, root);
    while (s.top != -1) {
        Node* curr = pop(&s);
        printf("%d ", curr->data);
        if (curr->right) push(&s, curr->right);
        if (curr->left) push(&s, curr->left);
    }
}

void inorderNonRecursive(Node* root) {
    Stack s; s.top = -1;
    Node* curr = root;
    while (curr != NULL || s.top != -1) {
        while (curr != NULL) {
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void postorderNonRecursive(Node* root) {
    if (root == NULL) return;
    Stack s1, s2;
    s1.top = -1; s2.top = -1;
    push(&s1, root);
    while (s1.top != -1) {
        Node* curr = pop(&s1);
        push(&s2, curr);
        if (curr->left) push(&s1, curr->left);
        if (curr->right) push(&s1, curr->right);
    }
    while (s2.top != -1) {
        printf("%d ", pop(&s2)->data);
    }
}
