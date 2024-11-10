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
    ll N, K, D;
    cin >> N >> K >> D;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector dp(N+1, vector(K+1, vector<ll>(D, -INF)));
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, D){
            rep(k, K){
                chmax(dp[i+1][k][j], dp[i][k][j]);
                chmax(dp[i+1][k+1][(j+A[i])%D], dp[i][k][j] + A[i]);
            }
            chmax(dp[i+1][K][j], dp[i][K][j]);
        }
    }
    ll ans = dp[N][K][0];
    if (ans < 0) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}