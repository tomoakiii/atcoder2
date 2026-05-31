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
typedef modint1000000007 mint;
int main(){
    ll N;
    cin >> N;
    vector dp(N+1, vector<mint>(4));
    // 0: nono, 1:yesno, 2:noyes, 3:yesyes
    dp[0][0] = 1;
    rep(i,N) {
        dp[i+1][0] += dp[i][0]*8;
        dp[i+1][1] += dp[i][1]*9 + dp[i][0];
        dp[i+1][2] += dp[i][2]*9 + dp[i][0];
        dp[i+1][3] += dp[i][3]*10 + dp[i][1] + dp[i][2];        
    }
    cout << dp[N][3].val() << endl;
    return 0;
}