#include "functions.h"

int main() {
    BSTNode* bstRoot = NULL;
    AVLNode* avlRoot = NULL;
    RBNode* rbRoot = NULL;
    BTreeNode* bTreeRoot = NULL;
    BPlusNode* bPlusRoot = NULL;

    int choice, data;

    while (1) {
        printf("\n--- Trees Menu ---\n");
        printf("1. BST (Insert & Inorder)\n");
        printf("2. AVL (Insert & Inorder)\n");
        printf("3. Red-Black Tree (Simplified Insert)\n");
        printf("4. B-Tree (Simplified)\n");
        printf("5. B+ Tree (Simplified)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Enter data for BST: ");
                scanf("%d", &data);
                bstRoot = insertBST(bstRoot, data);
                printf("BST Inorder: ");
                inorderBST(bstRoot);
                printf("\n");
                break;
            case 2:
                printf("Enter data for AVL: ");
                scanf("%d", &data);
                avlRoot = insertAVL(avlRoot, data);
                printf("AVL Inorder: ");
                inorderAVL(avlRoot);
                printf("\n");
                break;
            case 3:
                printf("Enter data for RB Tree: ");
                scanf("%d", &data);
                rbRoot = insertRB(rbRoot, data);
                printf("RB Inorder: ");
                inorderRB(rbRoot);
                printf("\n");
                break;
            case 4:
                printf("Enter data for B-Tree: ");
                scanf("%d", &data);
                bTreeRoot = insertBTree(bTreeRoot, data);
                traverseBTree(bTreeRoot);
                break;
            case 5:
                printf("Enter data for B+ Tree: ");
                scanf("%d", &data);
                bPlusRoot = insertBPlusTree(bPlusRoot, data);
                traverseBPlusTree(bPlusRoot);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
