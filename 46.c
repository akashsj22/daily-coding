#include <stdio.h>

void sort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void findMaxGuests(int Entry[], int Exit[], int n)
{
    sort(Entry, n);
    sort(Exit, n);

    int guests_in = 1;
    int max_guests = 1;
    int time = Entry[0];

    int i = 1, j = 0;

    while(i < n && j < n)
    {
        if(Entry[i] <= Exit[j])
        {
            guests_in++;

            if(guests_in > max_guests)
            {
                max_guests = guests_in;
                time = Entry[i];
            }
            i++;
        }
        else
        {
            guests_in--;
            j++;
        }
    }

    printf("%d %d", max_guests, time);
}

int main()
{
    int Entry[] = {1, 2, 10, 5, 5};
    int Exit[] = {4, 5, 12, 9, 12};
    int n = 5;

    findMaxGuests(Entry, Exit, n);

    return 0;
}
