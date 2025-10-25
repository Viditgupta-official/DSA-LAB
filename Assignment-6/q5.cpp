#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};
    head->next = second;
    second->next = third;
    third->next = head;

    if (isCircular(head))
        cout << "Circular Linked List";
    else
        cout << "Not Circular Linked List";
    return 0;
}
