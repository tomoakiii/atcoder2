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
    vector vu(N, vector<int>{});

    scc_graph G(N);
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].push_back({v,c});
        vu[v].push_back(u);
    }
    vector<bool> rch(N);
    auto dfs = [&](auto dfs, int cur)->void{
        rch[cur] = true;
        for(auto nx: vu[cur]) {
            if(rch[nx]) continue;
            dfs(dfs, nx);
        }
    };
    dfs(dfs, N-1);

    queue<int> que;
    que.push(0);
    vector<ll> dist(N, -INF);
    vector<ll> cnt(N);
    dist[0] = 0;
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        cnt[cur]++;
        if(cnt[cur] > 5*max(M,N)) dist[cur] = INF;
        for(auto [nx, c]: uv[cur]) {
            if(!rch[cur]) continue;
            ll nv = min(INF, dist[cur] + c);
            if(dist[nx] >= nv) continue;
            else dist[nx] = nv;
            que.push(nx);
        }
    }
    if(dist[N-1]>=INF) cout<<"inf"<<endl;
    else cout<<dist[N-1]<<endl;
    return 0;
}
