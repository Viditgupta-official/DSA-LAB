#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    int arr[MAX], top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if (top == MAX - 1) cout << "Stack Overflow\n";
        else arr[++top] = x;
    }
    void pop() {
        if (top == -1) cout << "Stack Underflow\n";
        else cout << "Popped: " << arr[top--] << "\n";
    }
    bool isEmpty() { return top == -1;}
    bool isFull() { return top == MAX - 1; }
    void peek() {
        if (isEmpty()) cout << "Stack Empty\n";
        else cout << "Top: " << arr[top] << "\n";
    }
    void display() {
        if (isEmpty()) cout << "Stack Empty\n";
        else {
            for (int i = top; i >= 0; i--) cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Stack s;
    int choice, val;
    while (true) {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 5: return 0;
        }
    }
}
