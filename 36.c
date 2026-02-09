#include <stdio.h>
#include <string.h>

int main() {
    char s[20];
    int i, j, flag = 1;

    scanf("%s", s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}


#include <stdio.h>

int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    int n = 5;
    printf("%d", fact(n));
    return 0;
}
