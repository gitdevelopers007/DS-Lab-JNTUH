#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Graph {
    int n; // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph* g, int vertices);
void addEdge(Graph* g, int start, int end);
void BFS(Graph* g, int startVertex);
void DFS(Graph* g, int startVertex);

#endif
