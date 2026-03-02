#include <stdio.h>

int maxSum(int arr[], int n, int k) {
    int max_sum = 0;
    int window_sum = 0;

    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    max_sum = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum)
            max_sum = window_sum;
    }

    return max_sum;
}

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("%d", maxSum(arr, n, k));

    return 0;
}
