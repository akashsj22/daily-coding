#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node *curr, Node *head) {
    if (head == nullptr)
        return;

    cout << curr->data << " ";

    if (curr->next == head)
        return;

    printList(curr->next, head);
}

int main() {
    Node *head = new Node(11);
    head->next = new Node(2);
    head->next->next = new Node(56);
    head->next->next->next = new Node(12);

    head->next->next->next->next = head;

    printList(head, head);

    return 0;
}
