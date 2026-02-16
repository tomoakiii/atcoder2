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
    ll N,M,K;  cin >> N >> M >> K;
    vector dp(N+1, vector<ll>(M+1,-INF));
    dp[0][0] = 0;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    ll ans = 0;
    rep(i,N) {
        if(B[i] > M) continue;
        chmax(dp[i][B[i]], A[i]);
        for(int j=i+1; j<N; j++) {
            if(j-i>K) break;
            rep(k,M) {
                ll nk = k + B[j];
                if(nk > M) continue;
                ll sm = dp[i][k] + A[j];
                chmax(dp[j][nk], sm);
            }
        }
    }
    rep(i,N+1) rep(j,M+1) chmax(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}