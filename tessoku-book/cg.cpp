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
    ll N; cin>>N;
    ll H=1500, W=1500;
    vector G(H+1, vector<int>(W+1));
    rep(i,N) {
        int X, Y; cin>>X>>Y;
        G[X][Y]++;
    }
    rep(i,H) rep(j,W+1) {
        G[i+1][j] += G[i][j];
    }
    rep(i,H+1) rep(j,W) {
        G[i][j+1] += G[i][j];
    }
    ll Q; cin>>Q;
    while(Q--) {
        ll a,b,c,d; cin>>a>>b>>c>>d;
        a--, b--;
        cout<< G[c][d] + G[a][b] - G[a][d] - G[c][b] << endl;
    }
    return 0;
}