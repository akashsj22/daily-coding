struct node* findMin(struct node* root)
{
    if (root == NULL || root->left == NULL)
        return root;
    return findMin(root->left);
}

struct node* findMax(struct node* root)
{
    if (root == NULL || root->right == NULL)
        return root;
    return findMax(root->right);
}
