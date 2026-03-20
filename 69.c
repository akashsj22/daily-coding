#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int val) {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void selectionSort() {
    struct node *i, *j, *min;
    int temp;

    for(i = head; i != NULL; i = i->next) {
        min = i;
        for(j = i->next; j != NULL; j = j->next) {
            if(j->data < min->data)
                min = j;
        }
        temp = i->data;
        i->data = min->data;
        min->data = temp;
    }
}

void removeEnd() {
    struct node *temp, *prev;

    if(head == NULL)
        return;

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

int main() {
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        create(val);
    }

    display();

    selectionSort();
    display();

    removeEnd();
    display();

    return 0;
}
