#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        // Rotate previous elements behind the new one
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackOneQueue s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30
    s.pop();
    cout << "Top after one pop: " << s.top() << endl; // 20

    s.push(40);
    cout << "Top after pushing 40: " << s.top() << endl; // 40

    s.pop();
    s.pop();
    cout << "Top after popping twice: " << s.top() << endl; // 10

    s.pop();
    s.pop(); // Underflow
    return 0;
}
