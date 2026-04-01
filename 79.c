#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int val)
{
    if (root == NULL)
        return create(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int findMin(struct node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct node* root)
{
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main()
{
    struct node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Minimum element: %d\n", findMin(root));
    printf("Maximum element: %d\n", findMax(root));

    return 0;
}
