#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == x)
        return mid;
    else if(arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, high, x);
}

int main()
{
    int arr[] = {2,4,6,8,10};
    int n =
