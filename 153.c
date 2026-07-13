#include <stdio.h>

#define V 4

int graph[V][V] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
};

int color[V];

int isSafe(int v, int c) {
    for(int i = 0; i < V; i++) {
        if(graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int main() {
    int m = 3;

    for(int i = 0; i < V; i++) {
        for(int c = 1; c <= m; c++) {
            if(isSafe(i, c)) {
                color[i] = c;
                break;
            }
        }
    }

    printf("Vertex : Color\n");

    for(int i = 0; i < V; i++)
        printf("%d : %d\n", i, color[i]);

    return 0;
}
