#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main () {
    string S;
    cin >> S;
    int stage=0;
    if (S[0] != '<' || S[S.size()-1] != '>'){
        cout << "No" << endl;
        return 0;
    }
    for (int i=1; i<S.size()-1; i++){
        if (S[i] != '=') {
            cout << "No" << endl;
            return 0;          
        } 
    }
    cout << "Yes" << endl;
    return 0;
}

