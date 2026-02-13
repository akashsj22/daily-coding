#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));
    Node *c = malloc(sizeof(Node));
    Node *d = malloc(sizeof(Node));

    a->data = 5;
    a->next = b;

    b->data = 15;
    b->next = c;

    c->data = 25;
    c->next = d;

    d->data = 35;
    d->next = NULL;

    printList(a);

    return 0;
}
