#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string arr[] = {"banana","apple","cherry"};
    int n = 3;
    sort(arr, arr+n);
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
