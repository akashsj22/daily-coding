#include <stdio.h>
#include <stdbool.h>

bool isNonDecreasing(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
}

int minOperations(int nums[], int n) {
    int count = 0;

    while(!isNonDecreasing(nums, n)) {

        int minSum = nums[0] + nums[1];
        int index = 0;

        for(int i = 1; i < n-1; i++) {
            int sum = nums[i] + nums[i+1];
            if(sum < minSum) {
                minSum = sum;
                index = i;
            }
        }

        nums[index] = nums[index] + nums[index+1];

        for(int i = index + 1; i < n - 1; i++) {
            nums[i] = nums[i + 1];
        }

        n--;
        count++;
    }

    return count;
}

int main() {
    int nums[] = {5,2,3,1};
    int n = 4;

    printf("%d\n", minOperations(nums, n));

    return 0;
}
