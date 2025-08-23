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
    string S, T;
    cin >> S >> T;
    ll ans = INF;
    rep(i,1+S.size() - T.size()) {
        ll nm = 0;
        rep(j, T.size()) {
            if(S[i+j] != T[j]) nm++;
        }
        chmin(ans, nm);
    }
    cout << ans << endl;
    return 0;
}