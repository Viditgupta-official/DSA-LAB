#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linkedlist {
    Node* head;
public:
    linkedlist() : head(nullptr) {}
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

    bool ispalindrome() {
        // Find the middle of the linked list
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            Node* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // If the number of nodes is odd, skip the middle node
        if (fast) {
            slow = slow->next;
        }

        // Compare the two halves
        Node* firstHalf = prev;
        Node* secondHalf = slow;

        while (firstHalf && secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};