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
    ll N, M, S[2], G[2];
    cin >> N >> M >> S[0] >> G[0] >> G[1];
    S[1]=G[0];
    rep(i,2)S[i]--,G[i]--;
    vector uv(N, vector<pair<ll,int>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    ll ans=0;
    rep(k,2){
        vector<ll> d(N,INF);
        d[S[k]]=0;
        priority_queue<pli,vector<pli>,greater<pli>> que;
        que.push({d[S[k]], S[k]});
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
        if(d[G[k]]==INF) {
            cout<<-1<<endl;
            return 0;
        }
        ans+=d[G[k]];
    }
    cout<<ans<<endl;
    return 0;
}