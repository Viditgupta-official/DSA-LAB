#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node *prev, *next;
        Node(int d) : data(d), prev(nullptr), next(nullptr) {}
    };
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertend(int val){
        Node*newNode = new Node(val); 
        if(!head){ head = newNode; return; }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertbegin(int val){
        Node* newNode = new Node(val);
        if(!head){ head = newNode; return; }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void deleteNode(int key) {
        Node *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << key << " deleted.\n";
    }

    void searchNode(int key) {
        Node *temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found!\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, key;

    do {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dll.insertbegin(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                dll.insertend(val);
                break;
            case 3:
                cout << "Enter key after which to insert: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                dll.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key before which to insert: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                dll.insertAfter(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                dll.searchNode(key);
                break;
            case 7:
                dll.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}