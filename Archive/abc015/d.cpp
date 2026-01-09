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
    ll W, N, K;
    cin >> W >> N >> K;
    ll M = 100*50;
    vector dp(K+1, vector<ll>(M + 1, INF));
    dp[0][0] = 0;
    rep(i,N) {
        ll a, b; cin>>a>>b;
        auto dp_new = dp;
        rep(k,K) {
            rep(p, M) {
                if(p+b > M) continue;
                chmin(dp_new[k+1][p+b], dp[k][p] + a);
            }
        }
        swap(dp,dp_new);
    }
    ll ans = 0;
    rep(k,K+1) rep(p,M+1) if(dp[k][p]<=W) chmax(ans, p);
    cout<<ans<<endl;
    return 0;
}