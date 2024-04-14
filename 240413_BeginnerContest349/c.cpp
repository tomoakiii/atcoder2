#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    string s, t;
    cin >> s >> t;
    int i = 0;
    for(auto c:s){
        char cc = 'A' + (c-'a');
        if (cc == t[i]){
            i++;
            if (i==3){
                cout << "Yes" << endl;
                return 0;
            } else if (i==2 && t[2] == 'X') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;       
    return 0;
}