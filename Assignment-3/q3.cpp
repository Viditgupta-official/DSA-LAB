#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    stack<char> s;
    for (char c : exp) {
        if (c=='(' || c=='[' || c=='{') s.push(c);
        else {
            if (s.empty()) return false;
            char t = s.top(); s.pop();
            if ((c==')' && t!='(') || (c==']' && t!='[') || (c=='}' && t!='{'))
                return false;
        }
    }
    return s.empty();
}

int main() {
    string exp; cin >> exp;
    if (isBalanced(exp)) cout << "Balanced\n";
    else cout << "Not Balanced\n";
}
