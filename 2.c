#include <stdio.h>

int val = 10;

void func() {
    // empty function
}

int main() {
    int var;
    var = 10;

    printf("%d\n", var);
    return 0;
}
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main() {
    printf("%d\n", sum(10, 20));
    return 0;
}
#include <stdio.h>

int val = 10;

int sum(int a, int b) {
    return a + b;
}

int main() {
    int var = 10;

    printf("Variable value: %d\n", var);
    printf("Sum: %d\n", sum(10, 20));

    return 0;
}
