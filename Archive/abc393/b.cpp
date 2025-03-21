#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string S;
    cin >> S;
    ll ans= 0;
    rep(i, (int)S.size()) {
        if(S[i] != 'A') continue;
        for (int j = i+1; j < (int)S.size(); j++) {
            if(S[j] != 'B') continue;
            int d = j - i;
            if(j + d >= S.size()) continue;
            if(S[j + d] != 'C') continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}