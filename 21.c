#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if (top >= 0)
        top--;
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    int arr[] = {10, 15, 8, 13, 5, 40, 12, 75, 50};
    int n = 9;

    for (int i = 0; i < n; i++)
        push(arr[i]);

    pop();
    pop();

    display();

    return 0;
}
