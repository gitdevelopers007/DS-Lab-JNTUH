#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int vertices;

void bfs(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int current, i;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear)
    {
        current = queue[front++];
        printf("%d ", current);

        for(i = 0; i < vertices; i++)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
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

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}




//Enter number of vertices: 4

Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

Enter starting vertex: 0

BFS Traversal: 0 1 2 3//