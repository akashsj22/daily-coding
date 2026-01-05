#include <stdio.h>

int main()
{
    int age = 20;
    float height = 5.7;
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Height: %.1f\n", height);
    printf("Grade: %c\n", grade);

    return 0;
}

#include <stdio.h>

int main() {
    int num = 3;
    printf("%d", num);
    return 0;
}

#include <stdio.h>

int main()
{
    int number = 10;
    printf("Initial value: %d\n", number);
    number = 25;
    printf("Updated value: %d\n", number);
    number = number + 5;
    printf("After adding 5: %d\n", number);

    return 0;
}
