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
    vector<ll> B(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    rep(i,N) B[i]=(uv[i].size()>=K);
    typedef pair<ll,int> pli;
    priority_queue<pli,vector<pli>,greater<pli>>que;
    que.push({0,0});
    vector<ll> dist(N,INF);
    dist[0]=0;
    while(!que.empty()){
        auto [d,cur]=que.top();
        que.pop();
        if(dist[cur]<d)continue;
        for(auto nx:uv[cur]){
            if(chmin(dist[nx], dist[cur]+B[nx]+1)){
                que.push({dist[nx],nx});
            }
        }
    }
    if(dist[N-1]==INF)cout<<-1<<endl;
    else cout<<dist[N-1]-B[N-1]<<endl;
    return 0;
}