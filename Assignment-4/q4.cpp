#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : s) {
        if (ch == ' ') continue; // ignore spaces if input has them
        freq[ch]++;
        q.push(ch);

        // Remove all repeating characters from queue front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    cout << "First non-repeating characters in stream: ";
    firstNonRepeating(s);

    return 0;
}
