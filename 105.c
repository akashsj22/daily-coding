#include <stdio.h>
#define V 5
#define INF 9999

int min(int dist[], int vis[]) {
    int m = INF, idx = -1;
    for (int i = 0; i < V; i++)
        if (!vis[i] && dist[i] < m)
            m = dist[i], idx = i;
    return idx;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], vis[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = min(dist, vis);
        vis[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!vis[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0,10,0,5,0},
        {10,0,1,2,0},
        {0,1,0,0,4},
        {5,2,0,0,2},
        {0,0,4,2,0}
    };

    dijkstra(graph, 0);
    return 0;
}
