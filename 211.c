#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* graph[V];

struct Node* newNode(int v, int w) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->w = w;
    n->next = NULL;
    return n;
}

void addEdge(int u, int v, int w) {
    struct Node* n = newNode(v, w);
    n->next = graph[u];
    graph[u] = n;

    n = newNode(u, w);
    n->next = graph[v];
    graph[v] = n;
}

int min(int dist[], int vis[]) {
    int m = INT_MAX, idx = -1;
    for (int i = 0; i < V; i++)
        if (!vis[i] && dist[i] < m)
            m = dist[i], idx = i;
    return idx;
}

void dijkstra(int src) {
    int dist[V], vis[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = min(dist, vis);
        vis[u] = 1;

        struct Node* t = graph[u];
        while (t) {
            if (!vis[t->v] && dist[u] + t->w < dist[t->v])
                dist[t->v] = dist[u] + t->w;
            t = t->next;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d %d\n", i, dist[i]);
}

int main() {
    addEdge(0,1,10);
    addEdge(0,3,5);
    addEdge(1,2,1);
    addEdge(1,3,2);
    addEdge(2,4,4);
    addEdge(3,4,2);

    dijkstra(0);
    return 0;
}
