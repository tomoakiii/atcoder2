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
    vector<ll> V(K+1);
    rep(i,K) {
        cin>>V[i+1];
        V[i+1]--;
    }
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    vector dist(K+1,vector<ll>(K+1));
    typedef pair<ll,int> pli;
    rep(k,K+1) {
        vector<ll> d(N,INF);
        d[V[k]]=0;
        priority_queue<pli,vector<pli>,greater<pli>> que;
        que.push({d[V[k]],V[k]});
        while(!que.empty()){
            auto [x,cur]=que.top();
            que.pop();
            if(x<d[cur])continue;
            for(auto [nx,w]:uv[cur]){
                if(chmin(d[nx], d[cur]+w)) {
                    que.push({d[nx],nx});
                }
            }
        }
        rep(k2,K+1) dist[k][k2]=d[V[k2]];
    }
    ll ful = 1ll<<(K+1);
    vector dp(ful, vector<ll>(K+1,INF));
    dp[1][0]=0;
    ll ans=INF;
    rep(S,ful){
        rep(last,K+1){
            if(!(S>>last & 1)) continue;
            rep(to,K+1){
                ll nS=S|(1ll<<to);
                chmin(dp[nS][to], dp[S][last]+dist[last][to]);
            }
        }
    }
    rep(i,K){
        chmin(ans, dp[ful-1][i] + dist[0][i]);
    }
    cout<<ans<<endl;
    return 0;
}