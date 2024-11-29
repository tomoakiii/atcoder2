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
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N);
    rep(i, N) cin >> X[i];
    map<int, ll> mp;
    rep(i,M) {
        int c;
        ll y;
        cin >> c >> y;
        mp[c] = y;
    }
    vector dp(N+1, vector<ll>(N+1, -INF));
    dp[0][0] = 0;
    rep(i,N) {
        rep(j,N) {
            dp[i+1][j+1] = dp[i][j] + X[i];
            dp[i+1][j+1] += mp[j+1]; 
            chmax(dp[i+1][0], dp[i][j]);
        }
    }
    ll ans = 0;
    rep(j,N+1) chmax(ans, dp[N][j]);
    cout << ans << endl;
    return 0;
}