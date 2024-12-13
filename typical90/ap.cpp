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
    ll K;
    cin >> K;
    const int M = K;
    vector dp(M+1, vector<mint>(9, 0));
    mint ans = 0;
    dp[0][0] = 1;
    rep(i, M) {
        for(int j=1; j<=9; j++) {
            if(i+j > M) break;
            rep(k, 9) {
                dp[i + j][(k + j)%9] += dp[i][k];
            }
            ans += dp[i+1][0];
        }
    }
    cout << ans.val() << endl;
    return 0;
}