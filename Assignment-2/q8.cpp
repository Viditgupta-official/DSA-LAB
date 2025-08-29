#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,2,1,4};
    int n = 6, distinct=0;
    for(int i=0;i<n;i++) {
        bool found = false;
        for(int j=0;j<i;j++) if(arr[i]==arr[j]) found=true;
        if(!found) distinct++;
    }
    cout<<"Distinct count: "<<distinct;
    return 0;
}
