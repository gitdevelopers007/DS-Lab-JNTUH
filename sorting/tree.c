#include <stdio.h>
#include <stdlib.h>
// Structure for tree node
struct Node
{
int data;
struct Node *left;
struct Node *right;
};
// Function to create a new node
struct Node* createNode(int value)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
// Function to insert a node into BST
struct Node* insert(struct Node* root, int value)
{
if (root == NULL)
return createNode(value);
if (value < root->data)
root->left = insert(root->left, value);
else
root->right = insert(root->right, value);
return root;
}
// Inorder traversal to print sorted elements
void inorder(struct Node* root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
int main()
{
int n, i;
printf("Enter number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter elements:\n");
for(i = 0; i < n; i++)
scanf("%d", &arr[i]);
struct Node* root = NULL;
// Insert elements into BST
for(i = 0; i < n; i++)
root = insert(root, arr[i]);
printf("Sorted elements in ascending order:\n");
// Inorder traversal gives sorted order
inorder(root);
return 0;
}

//Enter number of elements: 6
Enter elements:
45 20 10 30 60 50
Sorted elements in ascending order:
10 20 30 45 50 60//