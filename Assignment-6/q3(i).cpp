#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class doublyLinkedList {
    Node* head;
public:
    doublyLinkedList() : head(nullptr) {};

    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
int main(){
    doublyLinkedList dll;
    dll.insertEnd(20);
    dll.insertEnd(100);
    dll.insertEnd(40);
    dll.insertEnd(80);
    dll.insertEnd(60);

    cout << "Size of doubly linked list: " << dll.size() << endl;
    return 0;
}