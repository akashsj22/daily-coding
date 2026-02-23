#include <stdio.h>

void sort(int a[], int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
}

int main()
{
    int Entry[]={1,2,10,5,5};
    int Exit[]={4,5,12,9,12};
    int n=5;

    sort(Entry,n);
    sort(Exit,n);

    int guests=1,max=1,time=Entry[0];
    int i=1,j=0;

    while(i<n && j<n)
    {
        if(Entry[i]<=Exit[j])
        {
            guests++;
            if(guests>max)
            {
                max=guests;
                time=Entry[i];
            }
            i++;
        }
        else
        {
            guests--;
            j++;
        }
    }

    printf("%d %d",max,time);
    return 0;
}
