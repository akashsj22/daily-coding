#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
void removeNode() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}
