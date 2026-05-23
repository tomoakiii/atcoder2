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
    ll N, M, K;
    cin >> N >> M >> K;
    vector dist(M, vector<ll>(M,INF));
    rep(i,K) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        dist[u][v]=w;
        dist[v][u]=w;
    }
    rep(k,M)rep(i,M)rep(j,M) chmin(dist[i][j],dist[i][k]+dist[k][j]);
    ll ans=0;
    rep(i,N){
        int u,v;
        cin>>u>>v;
        u--, v--;
        ans += dist[u][v];
    }
    cout<<ans<<endl;

    return 0;
}