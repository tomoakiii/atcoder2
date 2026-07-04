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
    ll N,K,P;
    cin >> N >> K >> P;
    vector<ll> M(N);
    rep(i,N) cin>>M[i];
    vector uv(N, vector<ll>{});
    rep(i,K) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> E(P);
    rep(i,P) {
        cin>>E[i];
        E[i]--;
    }
    vector<ll> dist(N, INF);
    typedef pair<ll,int> pli;
    priority_queue<pli,vector<pli>,greater<pli>>que;
    dist[0]=0;
    que.push({dist[0],0});
    while(!que.empty()){
        auto [d,cur]=que.top();
        que.pop();
        if(dist[cur]<d)continue;
        for(auto nx:uv[cur]){
            if(chmin(dist[nx], dist[cur] + M[cur]*M[nx])){
                que.push({dist[nx],nx});
            }
        }
    }
    ll ans=INF;
    rep(i,P){
        chmin(ans, dist[E[i]]);
    }
    cout<<ans<<endl;
    return 0;
}