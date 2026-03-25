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

struct node* findMin(struct node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* findMax(struct node* root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node* findParent(struct node* root, int key)
{
    if (root == NULL)
        return NULL;

    if ((root->left != NULL && root->left->data == key) ||
        (root->right != NULL && root->right->data == key))
        return root;

    if (key < root->data)
        return findParent(root->left, key);
    else
        return findParent(root->right, key);
}

int main()
{
    struct node* root = NULL;
    int arr[] = {10, 8, 15, 12, 13, 7, 9, 17, 20, 18, 4, 5};
    int n = 12;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Minimum element: %d\n", findMin(root)->data);
    printf("Maximum element: %d\n", findMax(root)->data);

    struct node* parent = findParent(root, 17);

    if (parent != NULL)
        printf("Parent of 17: %d\n", parent->data);
    else
        printf("Parent not found\n");

    return 0;
}
