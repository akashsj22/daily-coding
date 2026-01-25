#include <stdio.h>

int celebrity(int mat[][3], int n) {
    int indegree[n], outdegree[n];

    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        outdegree[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;
    }

    return -1;
}

int main() {
    int mat[3][3] = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int result = celebrity(mat, 3);

    if (result == -1)
        printf("No Celebrity\n");
    else
        printf("Celebrity is person %d\n", result);

    return 0;
}
