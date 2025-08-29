#include <iostream>
using namespace std;

struct Element { int row, col, val; };

int main() {
    Element mat[3] = {{0,1,5},{1,0,8},{1,2,10}};
    int n=3;
    cout<<"Transpose:\n";
    for(int i=0;i<n;i++)
        cout<<mat[i].col<<" "<<mat[i].row<<" "<<mat[i].val<<endl;
    return 0;
}
