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
    ll N,M;
    cin >> N >> M;
    ll offs=5001;
    ll K=10000;
    vector G(K, vector<ll>(K));
    rep(i,N) {
        ll x,y,c; cin>>x>>y>>c;
        G[x+y+offs][x-y+offs]+=c;
    }
    rep(i,K-1)rep(j,K)G[i+1][j]+=G[i][j];
    rep(i,K)rep(j,K-1)G[i][j+1]+=G[i][j];

    rep(i,M) {
        ll x,y,k; cin>>x>>y>>k;
        ll u=x+y+k+offs, v=x-y+k+offs;
        ll u2=u-k-k-1, v2=v-k-k-1;
        ll ans = G[u][v]+G[u2][v2]-G[u][v2]-G[u2][v];
        cout<<ans<<endl;
    }
    return 0;
}