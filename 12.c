#include <stdio.h>

int main() {
    int var = 10;
    int *ptr = &var;

    printf("%d", ptr);

    return 0;
}

#include <stdio.h>

int main() {
    int *ptr1;
    char *ptr2;
    
    // Finding size using sizeof()
    printf("%zu\n", sizeof(ptr1));
    printf("%zu", sizeof(ptr2));
    
    return 0;
}

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*fptr)*
