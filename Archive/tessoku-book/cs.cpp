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
int main(){
    string S, T; cin>>S>>T;
    int s = S.size(), t = T.size();
    vector dp(s+1, vector<int>(t+1));
    rep(i,s+1) dp[i][0] = i;
    rep(j,t+1) dp[0][j] = j;
    rep(i,s) {
        rep(j,t) {
            if(S[i] == T[j]) {
                dp[i+1][j+1] = dp[i][j];
                continue;
            }
            int mn = dp[i][j];
            chmin(mn, dp[i][j+1]);
            chmin(mn, dp[i+1][j]);
            dp[i+1][j+1] = mn + 1;
        }
    }
    /*
    rep(i,s+1) {
        rep(j,t+1) cerr << dp[i][j] << " ";
        cerr << endl;
    }
    */
    cout << dp[s][t] << endl;
    return 0;
}