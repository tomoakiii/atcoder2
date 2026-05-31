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
typedef pair<ll,int> pli;
int main(){
    ll N,M;
    cin >> N >> M;
    vector uv(N, vector<pli>{});
    rep(i,M) {
        int u,v;
        ll d;
        cin>>u>>v>>d;
        u--, v--;
        uv[u].emplace_back(v,d);
    }
    for(auto &u: uv) sort(u.begin(), u.end());
    priority_queue<pli, vector<pli>, greater<pli>> que;

    rep(i,N) {
        vector<ll> dist(N,INF);
        for(auto [nx, w]: uv[i]) {
            if(dist[nx] <= w) continue;
            dist[nx] = w;
            que.push({w, nx});
        }
        while(!que.empty()){
            auto [d, u] = que.top();
            que.pop();
            if(dist[u] < d) continue;
            for(auto [nx, w]: uv[u]){
                if(dist[nx] <= d + w) continue;
                dist[nx] = d + w;
                que.push({dist[nx], nx});
            }
        }
        if(dist[i] == INF) cout<<-1<<endl;
        else cout<<dist[i]<<endl;
    }
    return 0;
}