#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

int main() {
    struct Activity a[] = {
        {1,2},
        {3,4},
        {0,6},
        {5,7},
        {8,9},
        {5,9}
    };

    int n = sizeof(a) / sizeof(a[0]);

    printf("Selected Activities:\n");

    int i = 0;
    printf("(%d,%d)\n", a[i].start, a[i].finish);

    for (int j = 1; j < n; j++) {
        if (a[j].start >= a[i].finish) {
            printf("(%d,%d)\n", a[j].start, a[j].finish);
            i = j;
        }
    }

    return 0;
}
