int findMin(struct node* root)
{
    if (root->left == NULL)
        return root->data;
    return findMin(root->left);
}

int findMax(struct node* root)
{
    if (root->right == NULL)
        return root->data;
    return findMax(root->right);
}
