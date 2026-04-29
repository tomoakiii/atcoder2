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
typedef pair<ll,int> pll;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<tuple<int,int,ll>> uvw(M);
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w; u--,v--;
        uvw[i] = make_tuple(u,v,w);
    }
    rep(i,K) {
        ll c; cin>>c; c--;
        auto [u,v,w]=uvw[c];
        uvw[c] = make_tuple(u,v,2*w);
    }
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        auto [u,v,w]=uvw[i];
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    priority_queue<pll,vector<pll>,greater<pll>> que;
    que.push({0,0});
    vector<ll> dist(N,INF);
    dist[0]=0;
    while(!que.empty()){
        auto [d,cur] = que.top();
        que.pop();
        if(dist[cur]<d) continue;
        for(auto [nx,w] : uv[cur]) {
            if(chmin(dist[nx], dist[cur] + w)) {
                que.push({dist[nx],nx});
            }
        }
    }
    if(dist[N-1]==INF)cout<<-1<<endl;
    else cout<<dist[N-1]<<endl;
    return 0;
}