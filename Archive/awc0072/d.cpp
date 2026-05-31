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
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    vector<bool> visit(N);
    vector<ll> dist(N);
    dist[0]=1;
    priority_queue<pli,vector<pli>,greater<pli>> que;
    que.push({P[0],0});
    ll ans=0;
    while(!que.empty()){
        auto [x,cur]=que.top();
        que.pop();
        if(visit[cur])continue;
        visit[cur]=true;
        chmax(ans, dist[cur]);
        for(auto nx:uv[cur]){
            if(visit[nx])continue;
            if(P[nx]<=P[cur])continue;
            chmax(dist[nx], dist[cur]+1);
            que.push({P[nx],nx});
        }
    }
    cout<<ans<<endl;
    return 0;
}