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

int main() {
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector dp(N+1, vector<ll>(2));
    rep(i,N) {
        chmax(dp[i+1][1], dp[i][0] + A[i]);
        chmax(dp[i+1][0], dp[i][1]);
        chmax(dp[i+1][0], dp[i][0]);
    }
    cout << max(dp[N][0],dp[N][1]) << endl;
    return 0;
}