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
mint dp[100][4][4][4];
int main(){
    ll N;
    cin >> N;
    // NG: AGC,ACG,GAC
    // A:0 G:1 C:2 T:3
    rep(i,4) dp[0][i][3][3] = 1;
    for(int i=1;i<N;i++) {
        rep(j,4) rep(k,4) rep(l,4) rep(m,4) {
            if( (j==0 && k==1 && l==2) || (j==0 && k==2 && l==1) || (j==1 && k==0 && l==2) ||
               (j==0 && k==1 && m == 2) || (j==0 && l==1 && m == 2) ) continue;
            dp[i][j][k][l] += dp[i-1][k][l][m];
        }
    }
    mint ans = 0;
    rep(j,4) rep(k,4) rep(l,4) ans += dp[N-1][j][k][l];
    cout<<ans.val()<<endl;
    return 0;
}