#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char ch : exp) {
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main() {
    string exp;
    cout << "Enter a postfix expression (single-digit operands, no spaces needed): ";
    getline(cin, exp);

    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}