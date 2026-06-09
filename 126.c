#include <stdio.h>

#define V 4

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}

struct Edge {
    int u, v, w;
};

void sort(struct Edge e[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].w < e[j + 1].w) {
                struct Edge t = e[j];
                e[j] = e[j + 1];
                e[j + 1] = t;
            }
        }
    }
}

void maxST(struct Edge e[], int E) {
    sort(e, E);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("Edge Weight\n");

    for (int i = 0; i < E; i++) {
        int u = e[i].u;
        int v = e[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d %d\n", u, v, e[i].w);
            unionSet(u, v);
        }
    }
}

int main() {
    struct Edge e[] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    int E = sizeof(e) / sizeof(e[0]);

    maxST(e, E);

    return 0;
}
