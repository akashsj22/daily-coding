#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertEnd(struct node *head, int data) {
    struct node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search(struct node *head, int key) {
    struct node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in the list\n", key);
}

int main() {
    struct node *head = NULL;

    head = insertEnd(head, 100);
    head = insertEnd(head, 20);
    head = insertEnd(head, 35);
    head = insertEnd(head, 30);
    head = insertEnd(head, 45);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    head = insertEnd(head, 80);
    head = insertEnd(head, 10);
    head = insertEnd(head, 90);
    head = insertEnd(head, 75);

    printf("Singly Linked List:\n");
    display(head);

    search(head, 90);
    search(head, 200);

    return 0;
}
