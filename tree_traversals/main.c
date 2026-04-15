#include "functions.h"

int main() {
    Node* root = NULL;
    int n, val;

    printf("Enter number of nodes to insert in BST: ");
    scanf("%d", &n);
    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\n--- Recursive Traversals ---\n");
    printf("Preorder: "); preorderRecursive(root); printf("\n");
    printf("Inorder: "); inorderRecursive(root); printf("\n");
    printf("Postorder: "); postorderRecursive(root); printf("\n");

    printf("\n--- Non-Recursive Traversals ---\n");
    printf("Preorder: "); preorderNonRecursive(root); printf("\n");
    printf("Inorder: "); inorderNonRecursive(root); printf("\n");
    printf("Postorder: "); postorderNonRecursive(root); printf("\n");

    return 0;
}
