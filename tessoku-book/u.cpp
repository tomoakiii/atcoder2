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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N; cin>>N;
    vector<ll> P(N),A(N);
    rep(i,N) {
        cin>>P[i]>>A[i];
        P[i]--;
    }
    vector dp(N, vector<ll>(N,-INF));
    dp[0][N-1] = 0;
    for(ll len = N; len>=0; len--) {
        rep(l, N-len+1) {
            ll r = l + len - 1;
            if(r<=l) continue;
            if(l < P[l] && P[l] <= r) {
                chmax(dp[l+1][r], dp[l][r] + A[l]);
            } else {
                chmax(dp[l+1][r], dp[l][r]);
            }
            if(l <= P[r] && P[r] < r) {
                chmax(dp[l][r-1], dp[l][r] + A[r]);
            } else {
                chmax(dp[l][r-1], dp[l][r]);
            }
        }
    }
    ll ans = 0;
    rep(i,N) rep(j,N) chmax(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}