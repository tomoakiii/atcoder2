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
    ll N,W; cin>>N>>W;
    vector<ll> w(N),v(N);
    rep(i,N) cin>>w[i]>>v[i];
    vector<ll> dp(W+1,-INF);
    dp[0] = 0;
    rep(i,N) {
        vector<ll> dp_new = dp;
        rep(j, W+1) {
            if(w[i]+j <= W) chmax(dp_new[w[i]+j], dp[j] + v[i]);
        }
        swap(dp,dp_new);
    }
    ll ans = 0;
    rep(i,W+1) chmax(ans, dp[i]);
    cout << ans << endl;
}