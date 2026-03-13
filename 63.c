#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *left,*right;
};

struct node* insert(struct node* r,int d){
if(r==NULL){
struct node* n=malloc(sizeof(struct node));
n->data=d; n->left=n->right=NULL;
return n;
}
if(d<r->data) r->left=insert(r->left,d);
else r->right=insert(r->right,d);
return r;
}

void inorder(struct node* r){
if(r){ inorder(r->left); printf("%d ",r->data); inorder(r->right); }
}

void preorder(struct node* r){
if(r){ printf("%d ",r->data); preorder(r->left); preorder(r->right); }
}

int count(struct node* r){
if(r==NULL) return 0;
return 1+count(r->left)+count(r->right);
}

int main(){
int a[]={50,15,8,20,40,10,25,70,45,80,100},i;
struct node* root=NULL;
for(i=0;i<11;i++) root=insert(root,a[i]);

printf("Inorder: "); inorder(root);
printf("\nPreorder: "); preorder(root);
printf("\nLeft subtree nodes: %d",count(root->left));
}
