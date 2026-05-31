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
    cin >> N;
    M = N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<bool> visit(N);
    vector<ll> cnum(N,0);
    vector<int> par(N,-1);
    vector<int> dist(N);
    auto dfs = [&](auto dfs, int cur, int d)->ll{
        visit[cur] = true;
        ll sm = 1;
        dist[cur] = d;
        for(auto nx: uv[cur]){
            if(visit[nx])continue;
            par[nx] = cur;
            sm += dfs(dfs, nx, d+1);
        }
        cnum[cur] = sm;
        return cnum[cur];
    };
    dfs(dfs, 0, 0);
    int wl = N-1;
    if(dist[N-1] > 2) rep(i, (dist[N-1]-1)/2) wl = par[wl];
    ll wn = cnum[wl];
    ll bn = N - wn;
    if(wn >= bn) cout<<"Snuke"<<endl;
    else cout<<"Fennec"<<endl;
    return 0;
}