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
    ll N, M, T;
    cin >> N >> M >> T;
    T--;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].emplace_back(v,c);
        uv[v].emplace_back(u,c);
    }
    vector<ll> dist(N, INF);
    dist[0] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push({0,0});
    while(!que.empty()) {
        auto [d, q]=que.top();
        que.pop();
        if(dist[q] < d) continue;
        for(auto [nx,c]:uv[q]){
            if(dist[nx] <= dist[q]+c) continue;
            dist[nx] = dist[q]+c;
            que.push({dist[nx],nx});
        }
    }
    if(dist[T] ==INF) cout<<-1<<endl;
    else cout<<2*dist[T]<<endl;
    return 0;
}