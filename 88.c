#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) return NULL; // Basic error check
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
