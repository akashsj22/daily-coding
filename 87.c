int findMin(struct node* root)
{
    struct node* temp = root;
    while (temp->left)
        temp = temp->left;
    return temp->data;
}

int findMax(struct node* root)
{
    struct node* temp = root;
    while (temp->right)
        temp = temp->right;
    return temp->data;
}
