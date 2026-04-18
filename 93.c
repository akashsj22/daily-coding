#include <stdio.h>

int main()
{
    int arr[] = {5, 8, 12, 20, 30};
    int x = 20;
    int i, n, found = 0;

    n = sizeof(arr) / sizeof(arr[0]);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            printf("Element found at index %d", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}
