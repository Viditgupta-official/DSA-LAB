#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void countAndDelete(int key) {
    int count = 0;
    while (head && head->data == key) { // handle head
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            count++;
        } else curr = curr->next;
    }
    cout << "Count: " << count << endl;
}

void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertEnd(1); insertEnd(2); insertEnd(1); insertEnd(2);
    display();
    countAndDelete(1);
    display();
}