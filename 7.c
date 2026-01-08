#include <stdio.h>

int main() {
    
    int age = 20;
    if (age >= 18) {
        printf("Eligible for vote");
    }
}

#include <stdio.h>

int main() {
    int age = 10;

    if (age >= 18) {
        printf("Eligible for vote");
    }
    else {
        printf("Not Eligible for vote");
    }
    return 0;
}

#include <stdio.h>

int main(){
    int age = 11;

    if (age >= 18) {
        if (age >= 60)
            printf("Eligible to vote (Senior Citizen)\n");
        else
            printf("Eligible for vote\n");
    }
    else {
        printf("Not eligible to vote (Under 18)\n");
        if (age >= 13) 
                printf("teenager\n");
            else
                printf("not a teenager\n");
        }

    return 0;
}

#include <stdio.h>

int main() {
    int var = 18;
    switch (var) {
    case 15:
        printf("You are a kid");
        break;
    case 18:
        printf("Eligible for vote");
        break;
    default:
        printf("Default Case is executed");
        break;
    }

    return 0;
}
