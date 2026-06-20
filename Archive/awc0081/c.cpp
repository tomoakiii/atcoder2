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
    ll N, M, S;
    cin >> N >> M >> S;
    S--;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    vector<ll> dist(N,INF);
    dist[S]=0;
    queue<pair<ll,int>> que;
    que.push({0,S});
    while(!que.empty()){
        auto [d,i] = que.front();
        que.pop();
        for(auto nx:uv[i]){
            if(chmin(dist[nx], d+1)) que.push({d+1,nx});
        }
    }
    ll ans=0;
    rep(i,N) {
        if(dist[i]==INF) {
            cout<<-1<<endl;
            return 0;
        }
        chmax(ans,dist[i]);
    }
    cout<<ans<<endl;
    return 0;
}