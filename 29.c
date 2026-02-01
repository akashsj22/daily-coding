#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        printf("Queue Full\n");
    else {
        if (front == -1) front = 0;
        q[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        printf("Deleted: %d\n", q[front++]);
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", q[i]);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
    return 0;
}
