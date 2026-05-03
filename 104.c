#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5

struct Edge {
    int src, dest, weight;
};

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int a = find(u);
    int b = find(v);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Edge edges[]) {
    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(edges[0]), compare);

    printf("Edges in MST:\n");

    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            unionSet(u, v);
        }
    }
}

int main() {
    struct Edge edges[E] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    kruskal(edges);
    return 0;
}
