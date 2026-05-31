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
typedef long double ld;
int main(){
    ll N,Wlm;cin>>N>>Wlm;
    vector<int> V(N);
    vector<ll> W(N);
    rep(i,N) cin>>W[i] >> V[i];
    vector<ll> dp(100001, INF);
    dp[0] = 0;
    rep(i,N) {
        auto dp_new = dp;
        rep(v,100001) {
            if(dp[v] == INF) continue;
            int v2 = v + V[i];
            chmin(dp_new[v2], dp[v]+W[i]);
        }
        swap(dp,dp_new);
    }
    ll ans = 0;
    rep(v,100001) {
        if(dp[v]<=Wlm) ans=v;
    }
    cout << ans << endl;
    return 0;
}