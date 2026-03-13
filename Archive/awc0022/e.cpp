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
    vector uv(N, vector<pair<int,ll>>{});
    vector mdis(N, vector<ll>(N,INF));
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
        mdis[u][v] = w;
        mdis[v][u] = w;
    }
    rep(k,N) rep(i,N) rep(j,N) chmin(mdis[i][j], mdis[i][k]+mdis[k][j]);
    vector dist(1ll<<N, vector<ll>(N,INF));
    dist[1][0] = 0;
    rep(k,1ll<<N) {
        rep(i,N) {
            rep(j,N) {
                chmin(dist[k|(1ll<<j)][j], dist[k][i] + mdis[i][j]);
            }
        }
    }
    ll full = 1ll<<N; full--;
    ll ans = INF;
    rep(i,N) chmin(ans, dist[full][i] + mdis[i][0]);
    if(ans>=INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}