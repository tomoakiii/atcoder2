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
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v,s;
        cin>>u>>v>>s;
        if(s==0) continue;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> dist(N, INF);
    dist[0]=0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        for(auto to:uv[now]){
            if(dist[to]!=INF) continue;
            dist[to]=dist[now]+1;
            q.push(to);
        }
    }
    if(dist[N-1]==INF) cout<<-1<<endl;
    else cout<<dist[N-1]<<endl;
    return 0;
}