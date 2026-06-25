#include <stdio.h>
#include <limits.h>

#define V 4

int minCost = INT_MAX;

void tsp(int graph[V][V], int visited[], int curr, int count, int cost) {
    if (count == V && graph[curr][0]) {
        if (cost + graph[curr][0] < minCost)
            minCost = cost + graph[curr][0];
        return;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[curr][i]) {
            visited[i] = 1;
            tsp(graph, visited, i, count + 1, cost + graph[curr][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    int graph[V][V] = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };

    int visited[V] = {0};
    visited[0] = 1;

    tsp(graph, visited, 0, 1, 0);

    printf("Minimum Cost = %d", minCost);

    return 0;
}
