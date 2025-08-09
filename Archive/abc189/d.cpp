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


int main () {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    vector dp(N+1, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;
    
    rep(i,N) {
        if(S[i] == "AND") {
            dp[i+1][0] += 2*dp[i][0] + dp[i][1];
            dp[i+1][1] += dp[i][1];
        } else {
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][0] + 2*dp[i][1];
        }
    }
    cout << dp[N][1] << endl;
    
    return 0;
}
