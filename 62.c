#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }

    if(data<root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);

    return root;
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int count(struct node* root)
{
    if(root==NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

int main()
{
    struct node* root=NULL;

    int arr[]={50,15,8,20,40,10,25,70,45,80,100};
    int n=11;

    for(int i=0;i<n;i++)
        root=insert(root,arr[i]);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    int leftCount = count(root->left);

    printf("\nNumber of elements in left subtree: %d",leftCount);

    return 0;
}
