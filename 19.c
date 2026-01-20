#include <stdio.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

void dequeue() {
    front++;
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int count() {
    return rear - front + 1;
}

int main() {
    enqueue(10);
    enqueue(25);
    enqueue(20);
    enqueue(50);
    enqueue(45);
    enqueue(75);
    enqueue(60);
    enqueue(80);
    enqueue(95);
    enqueue(40);

    printf("Queue before Dequeue:\n");
    display();
    printf("Count = %d\n", count());

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    printf("Queue after Dequeue:\n");
    display();
    printf("Count = %d\n", count());

    return 0;
}
