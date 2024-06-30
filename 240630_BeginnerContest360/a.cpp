#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string s;
    cin >> s;

    rep(i,3){
        if (s[i] == 'R') {
            cout << "Yes" << endl;
            return 0;
        }
        if (s[i] == 'M') {
            cout << "No" << endl;
            return 0;
        }
    }

    return 0;
}