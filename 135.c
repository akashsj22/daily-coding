#include <stdio.h>

struct Item {
    int weight, profit;
    float ratio;
};

void sort(struct Item a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j].ratio < a[j + 1].ratio) {
                struct Item temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Item a[] = {{10,60,6.0}, {20,100,5.0}, {30,120,4.0}};
    int n = 3, W = 50;
    float profit = 0;

    sort(a, n);

    for(int i = 0; i < n; i++) {
        if(W >= a[i].weight) {
            profit += a[i].profit;
            W -= a[i].weight;
        }
        else {
            profit += a[i].ratio * W;
            break;
        }
    }

    printf("Maximum Profit = %.2f", profit);

    return 0;
}
