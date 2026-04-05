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
