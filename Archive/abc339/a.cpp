#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    auto c = S.end();
    c--;
    while(*c != '.'){
        c--;
    }
    c++;
    for( ; c != S.end() ; c++){
        cout << *c;
    }
    cout << endl;
    return 0;
}

