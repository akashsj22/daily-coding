#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

int search(int key) {
    for (int i = top; i >= 0; i--)
        if (stack[i] == key)
            return i;
    return -1;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    int key = 30;
    int pos = search(key);

    if (pos != -1)
        printf("Found at position %d\n", pos);
    else
        printf("Not found\n");

    return 0;
}
