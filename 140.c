#include <stdio.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

void sortJobs(struct Job jobs[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    int n = 5;

    sortJobs(jobs, n);

    int slot[10] = {0};
    char result[10];

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline; j > 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobs[i].id;
                break;
            }
        }
    }

    printf("Selected Jobs: ");

    for(int i = 1; i <= 3; i++) {
        if(slot[i])
            printf("%c ", result[i]);
    }

    return 0;
}
