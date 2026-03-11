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

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int findMin(struct node* root)
{
    while(root->left!=NULL)
        root=root->left;

    return root->data;
}

int main()
{
    struct node* root=NULL;

    int arr[]={100,30,10,20,40,35,45,60,55};
    int n=9;

    for(int i=0;i<n;i++)
        root=insert(root,arr[i]);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nMinimum element: %d",findMin(root));

    return 0;
}
