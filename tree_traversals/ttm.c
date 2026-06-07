#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
int data;
struct Node *left;
struct Node *right;
};
struct Node *createNode(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
struct Node *insertNode(struct Node *root, int data)
{ if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insertNode(root->left, data);
} else {
root->right = insertNode(root->right, data);
}
return root;
}
struct Node *createTree()
{ struct Node *root = NULL;
int n, value, i;
printf("How many nodes? ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{ printf("Enter value %d: ", i +
1); scanf("%d", &value);
root = insertNode(root, value);
}
return root;
}
void recursivePreorder(struct Node *root)
{ if (root != NULL) {
printf("%d ", root->data);
recursivePreorder(root->left);
recursivePreorder(root->right);
}
}
void recursiveInorder(struct Node *root)
{ if (root != NULL) {
recursiveInorder(root->left);
printf("%d ", root->data);
recursiveInorder(root->right);
}
}
void recursivePostorder(struct Node *root)
{ if (root != NULL) {

recursivePostorder(root->left);
recursivePostorder(root->right);
printf("%d ", root->data);
}
}
void nonRecursivePreorder(struct Node *root)
{ struct Node *stack[MAX];
int top = -1;
if (root == NULL)
{ printf("Tree is empty\n");
return;
}
stack[++top] = root;
while (top != -1) {
root = stack[top--];
printf("%d ", root->data);
if (root->right != NULL)
{ stack[++top] = root->right;
}
if (root->left != NULL)
{ stack[++top] = root->left;
}
}
}
void nonRecursiveInorder(struct Node *root)
{ struct Node *stack[MAX];
int top = -1;
while (root != NULL || top != -1)
{ while (root != NULL) {
stack[++top] = root;
root = root->left;
}
root = stack[top--];
printf("%d ", root->data);
root = root->right;
}
}
void nonRecursivePostorder(struct Node *root)
{ struct Node *stack1[MAX], *stack2[MAX];
int top1 = -1, top2 = -1;
if (root == NULL)
{ printf("Tree is empty\n");
return;
}
stack1[++top1] = root;
while (top1 != -1) {
root = stack1[top1--];
stack2[++top2] = root;
if (root->left != NULL)
{ stack1[++top1] = root->left;
}
if (root->right != NULL)
{ stack1[++top1] = root-
>right;
}
}
while (top2 != -1) {
printf("%d ", stack2[top2--]->data);
}
}
int main() {
struct Node *root = NULL;
int choice;
do {
printf("\nTree Traversal Methods\n");
printf("1. Create tree\n");

printf("2. Recursive Preorder\n");
printf("3. Recursive Inorder\n");
printf("4. Recursive Postorder\n");
printf("5. Non-Recursive Preorder\n");
printf("6. Non-Recursive Inorder\n");
printf("7. Non-Recursive Postorder\n");
printf("8. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice)
{ case 1:
root = createTree();
break;
case 2:
printf("Recursive Preorder: ");
recursivePreorder(root);
printf("\n");
break;
case 3:
printf("Recursive Inorder: ");
recursiveInorder(root);
printf("\n");
break;
case 4:
printf("Recursive Postorder: ");
recursivePostorder(root);
printf("\n");
break;
case 5:
printf("Non-Recursive Preorder: ");
nonRecursivePreorder(root);
printf("\n");
break;
case 6:
printf("Non-Recursive Inorder: ");
nonRecursiveInorder(root);
printf("\n");
break;
case 7:
printf("Non-Recursive Postorder: ");
nonRecursivePostorder(root);
printf("\n");
break;
case 8:
printf("Exiting...\n");
break;
default:
printf("Invalid choice\n");
}
} while (choice != 8);
return 0;
}

//Sample Output
Sample Output:
Tree Traversal Methods
1. Create tree
2. Recursive Preorder
3. Recursive Inorder
4. Recursive Postorder
5. Non-Recursive Preorder
6. Non-Recursive Inorder
7. Non-Recursive Postorder
8. Exit
Enter choice: 1
How many nodes? 5
Enter value 1: 40
Enter value 2: 20
Enter value 3: 60
Enter value 4: 10
Enter value 5: 30
Enter choice: 2
Recursive Preorder: 40 20 10 30 60
Enter choice: 6
Non-Recursive Inorder: 10 20 30 40 60//