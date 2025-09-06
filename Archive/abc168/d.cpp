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
        uv[v].emplace_back(u);
    }
    vector<ll> dist(N, INF);
    queue<pair<int,ll>> que;
    vector<int> pre(N,-1);
    pre[0] = 0;
    que.push({0,0});
    while(!que.empty()) {
        auto [q,d] = que.front();
        que.pop();
        if(dist[q] < d) continue;
        for(auto nx: uv[q]) {
            if(dist[nx] > d + 1) {
                dist[nx] = d + 1;
                que.push({nx,dist[nx]});
                pre[nx] = q;
            }
        }
    }
    rep(i,N) if(pre[i]==-1) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    rep(i,N-1) cout<<pre[i+1]+1<<endl;
    return 0;
}