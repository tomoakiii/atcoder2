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
    vector uv(N, vector<ll>(N,-INF));
    vector vu(N, vector<ll>(N,-INF));

    scc_graph G(N);
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u][v] = c;
        uv[v][u] = c;
    }
    vector rch(2, vector<bool>(N));
    auto dfs = [&](auto dfs, int cur, int id)->void{
        rch[id][cur] = true;
        rep(nx, N) {
            if(uv[cur][nx] == -INF) continue;
            if(rch[id][nx]) continue;
            dfs(dfs, nx, id);
        }
    };
    dfs(dfs, 0, 0);
    swap(uv,vu);
    dfs(dfs, N-1, 1);
    swap(uv,vu);
    rep(i,N) {
        if(!(rch[0][i] && rch[1][i])) {
            rep(j,N) {
                uv[i][j] = uv[j][i] = vu[i][j] = vu[j][i] = -INF;
            }
        }
    }
    rep(i,N) rep(j,N) {
        if(uv[i][j] != -INF) G.add_edge(i,j);
    }
    for(auto gv: G.scc()) {
        if(gv.size()<=1) continue;
        cout << "inf" << endl;
        return 0;
    }

    queue<pair<int,ll>> que;
    que.push({0,0});
    vector<ll> dist(N, -INF);
    while(!que.empty()) {
        auto [q,v] = que.front();
        que.pop();
        if(dist[q] > v) continue;
        rep(nx, N) {
            if(uv[q][nx] == -INF) continue;
            if(dist[nx] >= v + uv[q][nx]) continue;
            dist[nx] = v + uv[q][nx];
            que.push({nx, dist[nx]});
        }
    }
    cout<<dist[N-1]<<endl;
    return 0;
}
