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
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        ll w; cin>>w;
        if(w<K) continue;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> dist(N,INF);
    dist[0]=0;
    queue<ll> que;
    que.push(0);
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        for(auto nx:uv[cur]){
            if(chmin(dist[nx],dist[cur]+1)) {
                que.push(nx);
            }
        }
    }
    if(dist[N-1]==INF) cout<<-1<<endl;
    else cout<<dist[N-1]<<endl;
    return 0;
}