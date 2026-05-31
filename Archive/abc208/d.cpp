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
    ll N, M;
    cin >> N >> M;
    vector dist(N, vector<ll>(N, INF));    
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        dist[u][v] = c;
    }
    
    ll sm = 0;
    rep(k,N) rep(i,N) rep(j,N) {
        if(i==j)continue;
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
        if(dist[i][j] < INF) sm += dist[i][j];
    }
    cout<<sm<<endl;
    
    return 0;
}