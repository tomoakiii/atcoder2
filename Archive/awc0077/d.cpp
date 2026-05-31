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
    vector<ll> F(N);
    rep(i,N){
        cin>>F[i];
        F[i]--;
    }
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    typedef tuple<ll,int, ll> pli;
    priority_queue<pli,vector<pli>,greater<pli>>que;
    vector dist(N,vector<ll>(K,INF));
    dist[0][F[0]]=0;
    que.push(make_tuple(dist[0][F[0]],0,F[0]));
    while(!que.empty()){
        auto [q, cur, f]=que.top();
        que.pop();
        if(dist[cur][f]<q)continue;
        for(auto [nx,w]:uv[cur]){
            ll f2=min(f,F[cur]);
            if(chmin(dist[nx][f2], dist[cur][f]+w*(f2+1))){
                que.push(make_tuple(dist[nx][f2],nx,f2));
            }
        }
    }
    ll ans=INF;
    rep(i,K)chmin(ans,dist[N-1][i]);
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}