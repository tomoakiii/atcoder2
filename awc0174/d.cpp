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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector<ll> U(M),V(M),W(M);
    vector uv(N, vector<pair<ll,int>>{});
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        U[i]=u, V[i]=v, W[i]=w;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    int K; cin>>K;
    vector<bool> ex(M,true);
    rep(i,K){
        int j; cin>>j; j--;
        ex[j]=false;
    }
    vector uv2(N, vector<pair<ll,int>>{});
    rep(i,M){
        if(!ex[i])continue;
        int u=U[i], v=V[i];
        ll w=W[i];
        uv2[u].emplace_back(v,w);
        uv2[v].emplace_back(u,w);
    }
    typedef pair<ll,int> pli;
    rep(kkk,2){
        vector<ll> dist(N,INF);
        dist[0]=0;
        priority_queue<pli,vector<pli>,greater<pli>> que;
        que.push({dist[0],0});
        while(!que.empty()){
            auto [q,i]=que.top();
            que.pop();
            if(dist[i]<q)continue;
            for(auto [nx,w]:uv[i]){
                if(chmin(dist[nx],dist[i]+w))que.push({dist[nx],nx});
            }
        }
        if(dist[N-1]==INF)cout<<-1<<endl;
        else cout<<dist[N-1]<<endl;
        swap(uv,uv2);
    }
    return 0;
}