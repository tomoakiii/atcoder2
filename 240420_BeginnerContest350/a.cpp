#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    string s;
    cin >> s;
    int z = 0;
    z += (s[3]-'0')*100 + (s[4]-'0')*10 + (s[5]-'0');
    if(z>=1 && z<=349 && z!=316) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}