#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    bool b = true;
    rep(i, N) {
        if (S[i] == T[i]) continue;
        if (S[i] == '1' && T[i] == 'l') continue;
        if (S[i] == 'l' && T[i] == '1') continue;
        if (S[i] == '0' && T[i] == 'o') continue;
        if (S[i] == 'o' && T[i] == '0') continue;
        b = false;
    }
    cout << ((b)?"Yes":"No") << endl;
    return 0;
}