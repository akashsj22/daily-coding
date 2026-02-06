#include <stdio.h>

int main() {
    int a[10] = {10, 20, 30, 40, 50};
    int n = 5, pos = 3, x = 25;

    for (int i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;
    n++;

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    pos = 4;
    for (int i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

#include <stdio.h>

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int key = 30, flag = 0;

    for (int i = 0; i < 5; i++) {
        if (a[i] == key) {
            printf("Found at position %d", i + 1);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Not found");

    return 0;
}
