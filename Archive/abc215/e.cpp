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
    string S;
    cin >> S;
    mint ans = 0;
    vector dp(N+1, vector(1<<10, vector<mint>(11)));
    dp[0][0][10] = 1;
    rep(i,N) {
        rep(j,1<<10) {
            int c = S[i] - 'A';
            rep(k, 11) {
                // not select
                dp[i+1][j][k] += dp[i][j][k];
            }
            // continuous select
            dp[i+1][j][c] += dp[i][j][c];
            if(j>>c & 1) {
                // continue;
            } else {
                rep(k, 11) {
                    // select 1st time
                    if(k != c) dp[i+1][j | 1<<c][c] += dp[i][j][k];
                }
            }
        }
    }
    rep(j, 1<<10) rep(k,10) ans += dp[N][j][k];
    cout<<ans.val()<<endl;
    
    return 0;
}