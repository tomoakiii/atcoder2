#include <bits/stdc++.h>
using namespace std;

int main(){
    char S[17];     
    cin >> S;
    for (int i = 1; i < 16; i+=2){
        cout << i << " " << S[i] << endl;
        if (S[i] != '0'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}