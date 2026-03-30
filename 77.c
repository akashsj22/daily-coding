#include <stdio.h>

int heap[50], n = 0;

void insert(int x) {
    int i = n;
    heap[n++] = x;

    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void display() {
    for(int i = 0; i < n; i++)
        printf("%d ", heap[i]);
}

int main() {
    int m, x;

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        insert(x);
    }

    display();
    return 0;
}
