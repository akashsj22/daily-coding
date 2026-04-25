#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

struct Node* createNode(char data, unsigned freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct Node* buildHuffmanTree(char data[], int freq[], int n) {
    struct Node *nodes[100];
    int i, j;

    for(i = 0; i < n; i++)
        nodes[i] = createNode(data[i], freq[i]);

    int size = n;

    while(size > 1) {
        int min1 = 0, min2 = 1;

        if(nodes[min1]->freq > nodes[min2]->freq) {
            int t = min1;
            min1 = min2;
            min2 = t;
        }

        for(i = 2; i < size; i++) {
            if(nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if(nodes[i]->freq < nodes[min2]->freq && i != min1) {
                min2 = i;
            }
        }

        struct Node* left = nodes[min1];
        struct Node* right = nodes[min2];

        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        if(min1 > min2) {
            int t = min1;
            min1 = min2;
            min2 = t;
        }

        for(i = min2; i < size - 1; i++)
            nodes[i] = nodes[i + 1];

        for(i = min1; i < size - 2; i++)
            nodes[i] = nodes[i + 1];

        nodes[size - 2] = newNode;
        size--;
    }

    return nodes[0];
}

void printCodes(struct Node* root, int arr[], int top) {
    if(root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if(root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if(!root->left && !root->right) {
        printf("%c: ", root->data);
        for(int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(data) / sizeof(data[0]);

    struct Node* root = buildHuffmanTree(data, freq, n);

    int arr[100], top = 0;
    printCodes(root, arr, top);

    return 0;
}
