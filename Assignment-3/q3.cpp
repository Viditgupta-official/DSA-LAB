#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    stack<char> s;
    for (char c : exp) {
        if (c=='(' || c=='[' || c=='{') s.push(c);
        else {
            if (s.empty()) return false;
            char top = s.top(); s.pop();
            if (c==')' && top!='(') return false;
            else if (c==']' && top!='[') return false;
            else if (c=='}' && top!='{') return false;
            else{};
            return true;
        }
    }
    return s.empty();
}

int main() {
    string exp; cin >> exp;
    if (isBalanced(exp)) cout << "Balanced\n";
    else cout << "Not Balanced\n";
}
