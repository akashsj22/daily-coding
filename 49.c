#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

struct Node* sortedInsert(struct Node* newnode, struct Node* sorted) {

    if (sorted == NULL || sorted->val >= newnode->val) {
        newnode->next = sorted;
        sorted = newnode;
    } 
    else {
        struct Node* curr = sorted;

        while (curr->next != NULL && curr->next->val < newnode->val) {
            curr = curr->next;
        }

        newnode->next = curr->next;
        curr->next = newnode;
    }

    return sorted;
}

struct Node* insertionSort(struct Node* head) {

    struct Node* sorted = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* next = curr->next;
        sorted = sortedInsert(curr, sorted);
        curr = next;
    }

    return sorted;
}

void printList(struct Node* curr) {
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main() {

    struct Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(2);

    head = insertionSort(head);

    printList(head);

    return 0;
}
