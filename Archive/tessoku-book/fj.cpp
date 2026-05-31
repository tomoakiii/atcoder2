//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp
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
typedef long double ld;
typedef pair<ld,int> pl;
int dp[300][11][300]; // 今、切れ数、最初のページ
int main() {
    ll N,M,K; cin>>N>>M>>K;
    vector point(N+1, vector<int>(N+1));
    rep(i,M) {
        int a, b; cin>>a>>b;
        rep(j,a+1) point[b][j]++;
    }
    rep(i,N+1) rep(j,K+1) rep(k,N+1) dp[i][j][k] = -INFi;
    dp[0][0][0] = 0;
    rep(i,N) {
        rep(j, K+1) {
            rep(k, N+1) {
                chmax(dp[i+1][j][k], dp[i][j][k] + point[i+1][k]);
                if(j+1<=K) chmax(dp[i+1][j+1][i+1], dp[i][j][k]);
            }
        }
    }
    int ans = 0;
    rep(k,N+1) chmax(ans, dp[N][K][k]);
    cout << ans << endl;
    return 0;
}