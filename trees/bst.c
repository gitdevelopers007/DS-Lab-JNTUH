#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *left;
struct Node *right;
};
struct Node *createNode(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
struct Node *insert(struct Node *root, int data)
{ if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insert(root->left, data);
} else if (data > root->data) {
root->right = insert(root->right, data);
}
return root;
}
void inorder(struct Node *root)
{ if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
int main() {
struct Node *root = NULL;
int n, value, i;
printf("Binary Search Tree\n");
printf("How many nodes? ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{ printf("Enter value %d: ", i +
1); scanf("%d", &value);
root = insert(root, value);
}
printf("Inorder traversal: ");
inorder(root);
printf("\n");
return 0;
}

//Sample Output
Sample Output:
Binary Search Tree
How many nodes? 5
Enter value 1: 50
Enter value 2: 30
Enter value 3: 70
Enter value 4: 20
Enter value 5: 40

Inorder traversal: 20 30 40 50 70//