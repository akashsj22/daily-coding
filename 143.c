#include <stdio.h>

#define V 6

int graph[V][V] = {
    {0,0,1,0,0,0},
    {0,0,1,1,0,0},
    {0,0,0,0,1,0},
    {0,0,0,0,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
};

int visited[V];
int stack[V], top = -1;

void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < V; i++) {
        if(graph[v][i] && !visited[i])
            dfs(i);
    }

    stack[++top] = v;
}

int main() {
    for(int i = 0; i < V; i++) {
        if(!visited[i])
            dfs(i);
    }

    printf("Topological Order: ");

    while(top != -1)
        printf("%d ", stack[top--]);

    return 0;
}
