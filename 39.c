#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    if (!head || !second || !third) {
        printf("Memory allocation failed\n");
        return 1;
    }

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Created linked list: ");
    printList(head);

    Node *temp = head;
    while (temp != NULL) {
        Node *next_node = temp->next;
        free(temp);
        temp = next_node;
    }

    return 0;
}
