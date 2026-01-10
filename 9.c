#include <stdio.h>

void hello() {
    printf("GeeksforGeeks\n");
}

int square(int x) {
    return x * x;
}

int main() {
    hello();

    int result = square(5);
    printf("Square of 5 is: %d", result);

    return 0;
}

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);
    printf("The sum is: %d", result);
    return 0;
}

