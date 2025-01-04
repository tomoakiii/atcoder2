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
    int G[9][9];
    rep(i,9) rep(j,9) G[i][j] = (i+1)*(j+1);
    int X;
    cin >> X;
    ll ans = 0;
    rep(i,9) rep(j,9) if(G[i][j] != X) ans+=G[i][j];
    cout << ans << endl;
    return 0;
}