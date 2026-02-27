#include <stdio.h>

int sum(int n)
{
    if (n == 1)
        return 1;

    return n + sum(n - 1);
}

int main()
{
    int n = 5;
    printf("%d", sum(n));
    return 0;
}
#include <stdio.h>

int sum(int n)
{
    if (n == 1)
        return 1;

    return n + sum(n - 1);
}

int main()
{
    int n = 5;
    printf("%d", sum(n));
    return 0;
}
