#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

struct Node {
    int vertex;
    int distance;
};

struct MinHeap {
    int size;
    struct Node* array[V * V];
};

struct Node* createNode(int v, int dist) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->distance = dist;
    return node;
}

void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->array[left]->distance < heap->array[smallest]->distance)
        smallest = left;

    if (right < heap->size && heap->array[right]->distance < heap->array[smallest]->distance)
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

struct Node* extractMin(struct MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    struct Node* root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

void insertHeap(struct MinHeap* heap, struct Node* node) {
    int i = heap->size++;
    heap->array[i] = node;

    while (i && heap->array[i]->distance < heap->array[(i-1)/2]->distance) {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    insertHeap(&heap, createNode(src, 0));

    while (heap.size > 0) {
        struct Node* minNode = extractMin(&heap);
        int u = minNode->vertex;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
                insertHeap(&heap, createNode(v, dist[v]));
            }
        }
    }

    printf("Vertex   Distance\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
