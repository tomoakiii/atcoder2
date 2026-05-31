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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,ll>>{});
    vector<ll> V;
    ll sm=0;
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
        sm+=w;
    }
    rep(i,N) {
        if(uv[i].size()%2==1) V.push_back(i);
    }
    ll K=V.size();
    if(K==0){
        cout<<sm<<endl;
        return 0;
    }
    vector dist(K,vector<ll>(K));
    typedef pair<ll,int> pli;
    rep(k,K) {
        vector<ll> d(N,INF);
        d[V[k]]=0;
        priority_queue<pli,vector<pli>,greater<pli>> que;
        que.push({d[V[k]],V[k]});
        while(!que.empty()){
            auto [x,cur]=que.top();
            que.pop();
            if(x>d[cur])continue;
            for(auto [nx,w]:uv[cur]){
                if(chmin(d[nx], d[cur]+w)) {
                    que.push({d[nx],nx});
                }
            }
        }
        rep(k2,K) dist[k][k2]=d[V[k2]];
    }

    ll ful = 1ll<<K;
    vector<ll> dp(ful,INF);
    dp[0]=0;
    rep(S,ful){
        if(dp[S]>=INF)continue;
        rep(last,K){
            if(S>>last & 1) continue;
            rep(to,K){
                if(to==last)continue;
                if(S>>to & 1) continue;
                ll nS=S|(1ll<<to)|(1ll<<last);
                chmin(dp[nS], dp[S]+dist[last][to]);
            }
        }
    }
    cout<<dp[ful-1]+sm<<endl;
    return 0;
}