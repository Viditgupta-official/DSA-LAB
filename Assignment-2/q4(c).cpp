#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World", res = "";
    for (char c : s)
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U')
            res += c;
    cout << res;
    return 0;
}
