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

struct node* findSecondMin(struct node* root)
{
    struct node* parent = NULL;

    while (root->left != NULL)
    {
        parent = root;
        root = root->left;
    }

    if (root->right != NULL)
    {
        root = root->right;
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    return parent;
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
    int arr[] = {35, 15, 40, 7, 10, 10, 28, 82, 53, 25, 3};
    int n = 11;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    struct node* min1 = findMin(root);
    struct node* min2 = findSecondMin(root);
    struct node* parent = findParent(root, 82);

    printf("Least elements: %d %d\n", min1->data, min2->data);

    if (parent != NULL)
        printf("Parent of 82: %d\n", parent->data);
    else
        printf("Parent not found\n");

    return 0;
}
