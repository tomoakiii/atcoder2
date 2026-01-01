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
    ll K,S; cin>>K>>S;
    ll ans = 0;
    rep(x,K+1) rep(y,K+1) {
        ll z = S-x-y;
        if(z<0) continue;
        if(z>K) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}