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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector dp(N+1, vector<ll>(M, -INF));
    rep(i,N) {
        dp[i+1][0] = max(dp[i][0], A[i]);        
        for(int j=1; j<M; j++) {            
            dp[i+1][j] = max(dp[i][j], dp[i][j-1] + (j+1)*A[i]);
        }
    }
    ll ans = -INF;
    rep(i,M) chmax(ans, dp[N][M-1]);    
    cout << ans << endl;
    return 0;
}