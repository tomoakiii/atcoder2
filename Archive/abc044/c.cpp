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
    ll N,A; cin>>N>>A;
    vector<ll> X(N);
    rep(i,N)cin>>X[i];
    vector dp(N+1, vector<ll>(A*N+1));
    dp[0][0] = 1;
    rep(i,N) {
        vector dp_new = dp;
        rep(j,N){
            rep(k, A*N) {
                if(k+X[i] > A*N) break;
                dp_new[j+1][k+X[i]] += dp[j][k];
            }
        }
        swap(dp,dp_new);
    }
    ll ans = 0;
    for(int i=1; i<=N; i++) {
        ll tgt = i * A;
        ans += dp[i][tgt];
    }
    cout << ans << endl;
    return 0;
}