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
    ll X,Y; cin>>X>>Y;
    vector dp(X+1, vector<mint>(Y+1));
    dp[0][0] = 1;
    rep(i, X) rep(j, Y) {
        if(i+1 <= X && j+2 <= Y) {
            dp[i+1][j+2] += dp[i][j];
        }
        if(i+2 <= X && j+1 <= Y) {
            dp[i+2][j+1] += dp[i][j];
        }
    }
    cout<<dp[X][Y].val()<<endl;
    return 0;
}