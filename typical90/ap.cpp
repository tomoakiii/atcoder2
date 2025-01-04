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
    vector dp(K+1, vector<mint>(9, 0));
    mint ans = 0;
    dp[0][0] = 1;
    mint k = 1;
    rep(i, K) {
        for(int j=1; j<=9; j++) {
            if (i + j > K) continue;
            rep(k, 9) {
                int p = (j + k) % 9;
                dp[i + j][p] += dp[i][k];
            }
        }
        k *= 10;
    }
    cout << dp[K][0].val() << endl;
    return 0;
}