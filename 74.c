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

struct node* findMax(struct node* root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node* findSecondMax(struct node* root)
{
    struct node* parent = NULL;

    while (root->right != NULL)
    {
        parent = root;
        root = root->right;
    }

    if (root->left != NULL)
    {
        root = root->left;
        while (root->right != NULL)
            root = root->right;
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
    int arr[] = {60, 25, 72, 15, 30, 68, 101, 13, 18, 47, 70, 34};
    int n = 12;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    struct node* max1 = findMax(root);
    struct node* max2 = findSecondMax(root);
    struct node* parent = findParent(root, 68);

    printf("Maximum elements: %d %d\n", max1->data, max2->data);

    if (parent != NULL)
        printf("Parent of 68: %d\n", parent->data);
    else
        printf("Parent not found\n");

    return 0;
}
