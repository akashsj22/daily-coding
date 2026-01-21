#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void removeLargest() {
    int max = stack[0], pos = 0;

    for (int i = 1; i <= top; i++) {
        if (stack[i] > max) {
            max = stack[i];
            pos = i;
        }
    }

    for (int i = pos; i < top; i++)
        stack[i] = stack[i + 1];

    top--;
    printf("Largest element removed: %d\n", max);
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    int arr[] = {10, 15, 8, 13, 5};
    int n = 5;

    for (int i = 0; i < n; i++)
        push(arr[i]);

    removeLargest();
    display();

    return 0;
}
