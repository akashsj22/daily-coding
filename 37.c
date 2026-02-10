#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("data.txt", "w");
    fprintf(fp, "Hello DSA");
    fclose(fp);

    fp = fopen("data.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    fclose(fp);

    return 0;
}

#include <stdio.h>

int main() {
    int n = 7, flag = 1;

    if (n <= 1)
        flag = 0;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Prime");
    else
        printf("Not Prime");

    return 0;
}
