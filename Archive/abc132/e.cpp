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
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    int S,T; cin>>S>>T; S--,T--;
    vector dist(N, vector<ll>(3,INF));
    queue<pair<int,int>> que;
    dist[S][0]=0;
    que.push({S,0});
    while(!que.empty()){
        auto [cur, i] = que.front();
        que.pop();
        int ni = (i+1)%3;
        for(auto nx:uv[cur]){
            if(chmin(dist[nx][ni], dist[cur][i]+1)) que.push({nx,ni});
        }
    }
    if(dist[T][0]==INF) cout<<-1<<endl;
    else cout<<dist[T][0]/3<<endl;
    return 0;
}