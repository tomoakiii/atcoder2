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
    vector<ll> S(N);
    rep(i,N)cin>>S[i];
    vector uv(N, vector<pair<int,ll>>{});
    vector dist(N, vector<ll>(N,INF));
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
        chmin(dist[u][v], w);
        chmin(dist[v][u], w);
    }
    rep(k,N)rep(i,N)rep(j,N) chmin(dist[i][j],dist[i][k]+dist[k][j]);
    vector<ll> C(N);
    rep(i,N)rep(j,N) {
        if(dist[i][j]>S[i] && i!=j)C[i]++;
    }
    ll ans=0;
    rep(i,N) for(int j=i+1;j<N;j++) {
        if(C[i]==C[j] && dist[i][j]<=S[i] && dist[j][i]<=S[j])ans++;
    }
    cout<<ans<<endl;
    return 0;
}