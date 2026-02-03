#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
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
    newNode->prev = temp;

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

struct node* deleteAll(struct node *head, int value) {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            struct node *del = temp;

            if (temp == head) {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            temp = temp->next;
            free(del);
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    struct node *head = NULL;

    int elements[] = {80, 20, 55, 70, 45, 40, 90, 80, 10, 12, 75};
    int n = 11;

    for (int i = 0; i < n; i++)
        head = insertEnd(head, elements[i]);

    printf("Doubly Linked List:\n");
    display(head);

    head = deleteAll(head, 90);
    head = deleteAll(head, 80);

    printf("After deleting 90 and both 80s:\n");
    display(head);

    return 0;
}
