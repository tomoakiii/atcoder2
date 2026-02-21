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
    string L; cin>>L;
    vector dp(L.size(), vector<mint>(2)); // 0: unknown, 1: confirmed
    dp[0][0] = 2;
    dp[0][1] = 1;
    for(int i=1; i<L.size(); i++) {
        if(L[i] == '1') {
            dp[i][0] += dp[i-1][0] * 2;
            dp[i][1] += dp[i-1][0] + dp[i-1][1] * 3;
        } else {
            dp[i][0] += dp[i-1][0];
            dp[i][1] += dp[i-1][1] * 3;
        }
    }
    mint ans = dp[L.size()-1][0];
    ans += dp[L.size()-1][1];
    cout << ans.val() << endl;
    return 0;
}