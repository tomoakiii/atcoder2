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
    ll N, M, K;
    cin >> N >> M >> K;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].emplace_back(v,c);
        uv[v].emplace_back(u,c);
    }
    priority_queue<pli,vector<pli>,greater<pli>>que;
    vector<ll> dist(N,INF);
    dist[0]=0;
    que.push({0,0});
    while(!que.empty()) {
        auto [q,i]=que.top();
        que.pop();
        if(dist[i]<q)continue;
        for(auto [nx,c]:uv[i]){
            if(chmin(dist[nx],dist[i]+c)){
                que.push({dist[nx],nx});
            }
        }
    }
    if(dist[N-1]<=K)cout<<dist[N-1]<<endl;
    else cout<<-1<<endl;
    return 0;
}