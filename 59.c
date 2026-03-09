#include<stdio.h>

int binarySearch(int arr[], int n, int x){
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == x)
            return mid;

        else if(arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50};
    int n = 5;
    int x = 30;

    int result = binarySearch(arr, n, x);

    if(result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);

    return 0;
}
