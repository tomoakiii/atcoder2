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
    ll R, C, K;
    cin >> R >> C >> K;
    auto G = vector(R+1, vector<ll>(C+1));
    rep(i,K) {
        ll r,c,v; cin >> r >> c >> v;
        r--, c--;
        G[r][c] += v;
    }
    auto dp = vector(R, vector(C, vector<ll>(4, -INF)));
    dp[0][0][0] = 0;        
    rep(y,R)rep(x,C) {
        for(int k=3; k>=0; k--) {
            chmax(dp[y][x][k+1], dp[y][x][k] + G[y][x]);
        }
        rep(k,4) {
            if(y<R-1) chmax(dp[y+1][x][0], dp[y][x][k]);
            if(x<C-1) {
                chmax(dp[y][x+1][k], dp[y][x][k]);
            }             
        }        
    }
    ll ans = 0;
    rep(k,4) chmax(ans, dp[R-1][C-1][k]);
    cout << ans << endl;
    return 0;
}