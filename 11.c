#include <stdio.h>

int main() {
    
    // declaring and initializing a string
    char str[] = "string";

    // printing the string
    printf("The string is: %s\n", str);

    return 0;
}

#include <stdio.h>

int main() {
    char str[] = "string";

    str[0] = 'R';
    printf("%c", str[0]);

    return 0;
}

#include <stdio.h>

void printStr(char str[]) {
    printf("%s", str);
}

int main() {
    char str[] = "string and string";

    printStr(str);
    return 0;
}

#include <stdio.h>

int main() {
    const char *str = "Hello World";

    printf("%s\n", str);

    return 0;
}

