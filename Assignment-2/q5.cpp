#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int diag[4] = {1,2,3,4}; // diagonal matrix
    cout << "Diagonal: ";
    for(int i=0;i<n;i++) cout<<diag[i]<<" ";
    return 0;
}