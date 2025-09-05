#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& A) {
    vector<int> result;
    stack<int> st;

    for (int num : A) {
        while (!st.empty() && st.top() >= num) {
            st.pop();
        }

        if (st.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(st.top());
        }

        st.push(num);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> ans = nearestSmallerToLeft(A);

    cout << "Nearest smaller elements to the left: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
