#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even to interleave." << endl;
        return;
    }

    queue<int> firstHalf;
    int half = n / 2;

    // Step 1: Move first half to another queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave the two halves
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements (even size): ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    cout << "Original Queue: ";
    display(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    display(q);

    return 0;
}
