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
    cin>> N;
    vector<mint> dp(10, 1);
    rep(i,N-1) {
        vector dp_new = dp;
        for(int j = 1; j <= 9; j++) {
            if(j >= 2) dp_new[j] += dp[j-1];
            if(j <= 8) dp_new[j] += dp[j+1];
        }
        swap(dp, dp_new);
    }
    mint ans = 0;
    for(int j = 1; j <= 9; j++) ans += dp[j];
    cout << ans.val() << endl;
    return 0;
}