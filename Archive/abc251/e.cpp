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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans;
    {
        vector dp(N+1, vector<ll>(2, INF));
        dp[0][0] = 0;
        rep(i, N) {
            chmin(dp[i+1][0], dp[i][1]);
            chmin(dp[i+1][1], dp[i][1] + A[i]);
            chmin(dp[i+1][1], dp[i][0] + A[i]);
        }
        ans = min(dp[N][1], dp[N][0]);
    }    
    vector dp(N+1, vector<ll>(2, INF));
    dp[0][1] = A[N-1];
    rep(i, N-1) {
        chmin(dp[i+1][0], dp[i][1]);
        chmin(dp[i+1][1], dp[i][1] + A[i]);
        chmin(dp[i+1][1], dp[i][0] + A[i]);
    }
    chmin(ans, min(dp[N-1][1], dp[N-1][0]));
    cout << ans << endl;
    return 0;
}
