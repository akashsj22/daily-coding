#include <stdio.h>

int main() {
    int arr[] = {2, 4, 8, 12, 16, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

#include <stdio.h>

int main() {
    int arr[5] = {2, 4, 8, 12, 16};

    printf("%d ", arr[2]);
    printf("%d ", arr[4]);
    printf("%d ", arr[0]);

    return 0;
}

#include <stdio.h>

int main() {
    int arr[5] = {2, 4, 8, 12, 16};

    arr[0] = 1;
    printf("%d", arr[0]);

    return 0;
}

#include <stdio.h>

int main() {
    int arr[5] = {2, 4, 8, 12, 16};

    printf("Printing Array Elements\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Printing Array Elements in Reverse\n");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}

#include <stdio.h>

int main() {
    int arr[5] = {2, 4, 8, 12, 16};

    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d", size);

    return 0;
}
