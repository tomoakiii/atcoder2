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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }

    typedef pair<ll,int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    vector<ll> dist(N, INF);
    dist[0] = 0;
    que.push({dist[0],0});
    while(!que.empty()){
        auto [d,i] = que.top();
        que.pop();
        if(dist[i] < d) continue;
        for(auto [nx, w] : uv[i]) {
            if(chmin(dist[nx], dist[i] + w)) {
                que.push({dist[nx],nx});
            }
        }
    }
    if(dist[N-1]==INF) cout<<-1<<endl;
    else cout<<dist[N-1]<<endl;
    return 0;
}