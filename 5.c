#include <stdio.h>

int main()
{
    int age = 20;
    float height = 5.7f;
    double pi = 3.14159;
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Height: %.1f\n", height);
    printf("Pi: %.5f\n", pi);
    printf("Grade: %c\n", grade);

    return 0;
}

#include <stdio.h>
void greet()
{
    printf("Hello, welcome!\n");
}

int main()
{
    greet();
    return 0;
}

#include <stdio.h>

int main()
{
    printf("The size of int: %d\n", sizeof(int));
    printf("The size of char: %d\n", sizeof(char));
    printf("The size of float: %d\n", sizeof(float));
    printf("The size of double: %d", sizeof(double));

    return 0;
}
