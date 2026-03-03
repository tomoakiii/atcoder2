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
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector dp(N+1, vector<ll>(M+1, -INF));
    dp[0][0] = 0;
    ll mx = 0;
    rep(i,N) {
        rep(j,M+1) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j + A[i] > M) continue;
            chmax(dp[i+1][j+A[i]], dp[i][j]+B[i]);
            chmax(mx, dp[i+1][j+A[i]]);
        }
    }
    vector<bool> ans(N);
    vector ok(N+1, vector<bool>(M+1));
    rep(j,M+1) {
        if(dp[N][j] == mx) ok[N][j] = true;
    }

    for(int i=N; i>=1; i--) {
        rep(j, M+1) {
            if(!ok[i][j]) continue;
            if(dp[i-1][j] == dp[i][j]) {
                ok[i-1][j] = true;
            }
            int nj = j-A[i-1];
            if(nj < 0) continue;
            if(dp[i-1][nj] == dp[i][j] - B[i-1]) {
                ok[i-1][nj] = true;
                ans[i-1] = true;
            }
        }
    }
    for(auto a:ans) {
        if(a) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}