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
    vector<string> S(8);
    rep(i,8) cin>>S[i];
    int grid[8][8];
    rep(i,8) rep(j,8) grid[i][j] =0;
    rep(i,8) rep(j,8) if(S[i][j] == '#') {
        rep(x,8) grid[i][x]=-1;
        rep(x,8) grid[x][j]=-1;
    }
    ll cnt = 0;
    rep(i,8) rep(j,8) if(grid[i][j] != -1) {
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}