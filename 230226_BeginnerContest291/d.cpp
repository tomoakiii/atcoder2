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
typedef modint998244353 mint;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];
    vector dp(N, vector<mint>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i=1; i<N; i++) {
        if (A[i] != A[i-1]) {
            dp[i][0] += dp[i-1][0];
        }
        if (A[i] != B[i-1]) {
            dp[i][0] += dp[i-1][1];
        }
        if (B[i] != A[i-1]) {
            dp[i][1] += dp[i-1][0];
        }
        if (B[i] != B[i-1]) {
            dp[i][1] += dp[i-1][1];
        }
    }
    mint ans = dp[N-1][0] + dp[N-1][1];
    cout << ans.val() << endl;
    return 0;
}