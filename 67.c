#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// CREATE NODE (insert at end)
void create(int value) {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// DELETE FIRST NODE
void delete_begin() {
    struct node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted\n");
}

// DELETE LAST NODE
void delete_end() {
    struct node *temp, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

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

    printf("Last node deleted\n");
}

// DISPLAY LIST
void display() {
    struct node *temp = head;

    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List:\n");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, i, val, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        create(val);
    }

    display();

    printf("\n1. Delete at beginning\n2. Delete at end\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        delete_begin();
    else if(choice == 2)
        delete_end();
    else
        printf("Invalid choice\n");

    display();

    return 0;
}
