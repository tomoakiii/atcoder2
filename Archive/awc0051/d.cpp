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
    ll N, M, K, T;
    cin >> N >> M >> K >> T;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        ll w; cin>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    vector<bool> P(N);
    rep(i,K) {
        int g; cin>>g; g--;
        P[g]=true;
    }
    typedef pair<ll,int> pli;
    priority_queue<pli,vector<pli>,greater<pli>>que;
    vector<ll> dist(N,INF);
    dist[0]=(P[0]?T:0);
    que.push({dist[0],0});
    while(!que.empty()){
        auto [d,cur]=que.top();
        que.pop();
        if(dist[cur]<d)continue;
        for(auto [nx,w]:uv[cur]){
            if(chmin(dist[nx], dist[cur]+w+(P[nx]?T:0))){
                que.push({dist[nx],nx});
            }
        }
    }
    cout<<dist[N-1]<<endl;
    return 0;
}