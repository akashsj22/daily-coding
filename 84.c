int findMin(struct node* root)
{
    if (root == NULL)
        return 9999;

    int left = findMin(root->left);
    int right = findMin(root->right);

    int min = root->data;
    if (left < min) min = left;
    if (right < min) min = right;

    return min;
}
int findMax(struct node* root)
{
    if (root == NULL)
        return -9999;

    int left = findMax(root->left);
    int right = findMax(root->right);

    int max = root->data;
    if (left > max) max = left;
    if (right > max) max = right;

    return max;
}
