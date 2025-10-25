#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = NULL; return; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int key) {
    if (!head) return;
    if (head->data == key) { deleteBeginning(); return; }
    Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next; pos++;
    }
    cout << "Not found\n";
}

// Display list
void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, key;
    do {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertAfter 4.DelBeg 5.DelEnd 6.DelNode 7.Search 8.Display 9.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; insertAtBeginning(val); break;
            case 2: cin >> val; insertAtEnd(val); break;
            case 3: cin >> key >> val; insertAfter(key, val); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: cin >> key; deleteNode(key); break;
            case 7: cin >> key; searchNode(key); break;
            case 8: display(); break;
        }
    } while (choice != 9);
}
