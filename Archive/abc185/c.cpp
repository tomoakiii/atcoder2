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

int main(){
    ll L; cin>>L;
    vector dp(201,vector<ll>(13,0));
    dp[0][0] = 1;
    for(ll x = 1; x < L; x++) {
        dp[x] = dp[x-1];
        rep(k, 11) {
            dp[x][k+1] += dp[x-1][k];
        }
    }
    cout << dp[L-1][11] << endl;
    return 0;
}