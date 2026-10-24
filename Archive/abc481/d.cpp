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

    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--,T--;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v,1);
    }
    rep(i,N){
        if(uv[i].empty())continue;
        sort(uv[i].begin(),uv[i].end());
        uv[i][0].second=0;
    }
    typedef pair<ll,int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    vector<ll> dist(N, INF);
    dist[S] = 0;
    que.push({dist[S],S});
    while(!que.empty()){
        auto [d,i] = que.top();
        que.pop();
        if(dist[i] < d) continue;
        for(auto [nx, w] : uv[i]) {
            if(chmin(dist[nx], dist[i] + w)) {
                que.push({dist[nx],nx});
            }
        }
    }
    if(dist[T]==INF) cout<<-1<<endl;
    else cout<<dist[T]<<endl;
    return 0;
}