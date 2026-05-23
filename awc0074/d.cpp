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
typedef pair<ll,int>pli;
int main(){
    ll N, M;
    cin >> N >> M;
    ll S,T,P; cin>>S>>T>>P;
    S--,T--,P--;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    vector<ll> dist(N,INF);
    dist[P]=0;
    priority_queue<pli,vector<pli>,greater<pli>>que;
    que.push({dist[P],P});
    while(!que.empty()){
        auto [d,cur]=que.top();
        que.pop();
        if(dist[cur]<d) continue;
        for(auto [nx,w]:uv[cur]){
            if(chmin(dist[nx], dist[cur]+w)){
                que.push({dist[nx],nx});
            }
        }
    }
    dsu UF(N);
    priority_queue<pair<ll,int>> dii;
    rep(i,N) {
        if(dist[i]==INF)continue;
        dii.push({dist[i],i});
    }
    ll ans=INF;
    vector<bool> visit(N);
    while(!dii.empty()){
        auto [d,i] = dii.top();
        dii.pop();
        visit[i]=true;
        for(auto [nx,w]:uv[i]){
            if(!visit[nx])continue;
            UF.merge(nx,i);
        }
        if(UF.same(S,T)) {
            cout<<d<<endl;
            return 0;
        }
    }
    cout<<"INF"<<endl;
    return 0;
}