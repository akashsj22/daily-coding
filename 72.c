#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *l, *r;
};

struct node* insert(struct node* t, int x) {
    if(t == NULL) {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = x;
        t->l = t->r = NULL;
    } else if(x < t->data)
        t->l = insert(t->l, x);
    else
        t->r = insert(t->r, x);
    return t;
}

void inorder(struct node* t) {
    if(t) {
        inorder(t->l);
        printf("%d ", t->data);
        inorder(t->r);
    }
}

int main() {
    struct node *root = NULL;
    int n, x, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);
    return 0;
}
