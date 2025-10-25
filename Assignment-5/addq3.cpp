#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void removeloop(Node* loop_node) {
    Node* ptr1 = head;
    Node* ptr2 = loop_node;
    while (ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL;
}

bool detectLoop() {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            removeloop(slow);
            return true;
        }
    }
    return false;
}

void insertEnd(int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int main(){
    for(int i=1;i<=5;i++) insertEnd(i);

    head->next->next->next->next->next = head->next;

    if(detectLoop()) cout << "\nLoop detected and removed\n";
    else cout << "No loop detected\n";

    Node* temp = head;
    while(temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
    return 0;
}

