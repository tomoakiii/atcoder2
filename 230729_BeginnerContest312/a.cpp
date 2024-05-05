#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
int main(){
    string s;
    cin >> s;
    if (s == "ACE" || s == "BDF" || s == "CEG" ||
        s== "DFA" || s== "EGB" || s=="FAC" || s=="GBD"){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

