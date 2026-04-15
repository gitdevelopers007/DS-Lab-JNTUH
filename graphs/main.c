#include "functions.h"

int main() {
    Graph g;
    int vertices, edges, start, end, choice, startVertex;

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (start end) for each edge:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    while (1) {
        printf("\n--- Graph Menu ---\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        printf("Enter starting vertex for traversal: ");
        scanf("%d", &startVertex);

        switch (choice) {
            case 1:
                BFS(&g, startVertex);
                break;
            case 2:
                DFS(&g, startVertex);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
