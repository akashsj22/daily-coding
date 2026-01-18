#include <stdio.h>

int stack[5], top = -1;

int main() {
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    top--;

    printf("After pop:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    return 0;
}
