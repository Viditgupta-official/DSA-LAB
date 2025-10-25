#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class circularLinkedList {
    Node* head;
public:
    circularLinkedList() : head(nullptr) {}

    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main(){
    circularLinkedList cll;
    cll.insertEnd(20);
    cll.insertEnd(100);
    cll.insertEnd(40);
    cll.insertEnd(80);
    cll.insertEnd(60);

    cout << "Size of circular linked list: " << cll.size() << endl;
    return 0;
}