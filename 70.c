#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *left,*right;
};

struct node* newNode(int d){
struct node* n=malloc(sizeof(struct node));
n->data=d; n->left=n->right=NULL;
return n;
}

int height(struct node* r){
if(r==NULL) return 0;
int l=height(r->left);
int h=height(r->right);
return (l>h?l:h)+1;
}

int main(){
struct node* root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);

printf("Height: %d",height(root));
}
