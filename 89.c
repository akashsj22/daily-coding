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

int search(struct node* r,int x){
if(r==NULL) return 0;
if(r->data==x) return 1;
return search(r->left,x)||search(r->right,x);
}

int main(){
struct node* root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);

if(search(root,2))
printf("Found");
else
printf("Not Found");
}
