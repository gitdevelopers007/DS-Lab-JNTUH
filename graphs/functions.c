#include "functions.h"

void initGraph(Graph* g, int vertices) {
    g->n = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int start, int end) {
    g->adj[start][end] = 1;
    g->adj[end][start] = 1; // For undirected graph
}

// Helper Queue for BFS
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX_VERTICES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    front = -1; rear = -1; // Reset queue

    printf("BFS Traversal: ");
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (front <= rear && front != -1) {
        int curr = dequeue();
        if (curr == -1) break;
        printf("%d ", curr);

        for (int i = 0; i < g->n; i++) {
            if (g->adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

void DFSHelper(Graph* g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < g->n; i++) {
        if (g->adj[v][i] == 1 && !visited[i]) {
            DFSHelper(g, i, visited);
        }
    }
}

void DFS(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal: ");
    DFSHelper(g, startVertex, visited);
    printf("\n");
}
