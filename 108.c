#include <stdio.h>

#define V 4
#define INF 9999

int minKey(int key[], int visited[]) {
    int min = INF, index;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }

    return index;
}

void prim(int graph[V][V]) {
    int parent[V];
    int key[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minKey(key, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge Weight\n");

    for (int i = 1; i < V; i++)
        printf("%d - %d %d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0,2,0,6},
        {2,0,3,8},
        {0,3,0,5},
        {6,8,5,0}
    };

    prim(graph);

    return 0;
}
