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
typedef pair<int,int> pii;
int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector dp(H+2, vector<mint>(W+2));
    vector X(H+2, vector<mint>(W+2));
    vector Y(H+2, vector<mint>(W+2));
    vector Z(H+2, vector<mint>(W+2));
    dp[1][1] = X[1][1] = Y[1][1] = Z[1][1] = 1;
    for(ll i=1;i<=H; i++) for(ll j=1; j<=W; j++) {
        if(S[i-1][j-1] == '#') continue;
        dp[i][j] += X[i-1][j];
        dp[i][j] += Y[i][j-1];
        dp[i][j] += Z[i-1][j-1];        
        X[i][j] = dp[i][j] + X[i-1][j];
        Y[i][j] = dp[i][j] + Y[i][j-1];
        Z[i][j] = dp[i][j] + Z[i-1][j-1];        
    }
    cout << dp[H][W].val() << endl;
    return 0;
}