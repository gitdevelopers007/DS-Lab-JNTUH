#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int vertices;

void dfs(int vertex)
{
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for(i = 0; i < vertices; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}


// Enter number of vertices: 4

Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

Enter starting vertex: 0

DFS Traversal: 0 1 3 2 //