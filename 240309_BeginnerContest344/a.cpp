#include <bits/stdc++.h>
using namespace std;

int main () {
    string S;
    cin >> S;
    bool b = true;
    for (char c: S){
        if (c=='|') {
            b = !b;
        } else if (b) {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}

