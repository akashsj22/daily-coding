#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    push(10);
    push(20);
    push(30);

    display();
    return 0;
}
