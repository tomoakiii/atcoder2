#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define ALLOCSIZE 2000000
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    cin >> N;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,N-1) {
        int u,v;
        ll d;
        cin>>u>>v>>d;
        u--, v--;
        uv[u].emplace_back(v,d);
        uv[v].emplace_back(u,d);
    }
    ll Q,K; cin>>Q>>K; K--;
    vector<ll> depth(N,INF);
    auto dfs = [&](auto dfs, int cur, int pre, ll d)->void{
        depth[cur] = d;
        for(auto [nx, v]: uv[cur]){
            if(nx == pre) continue;
            dfs(dfs, nx, cur, d+v);
        }
    };
    dfs(dfs, K, -1, 0);

    while(Q--) {
        ll x, y; cin>>x>>y; x--, y--;
        cout << depth[x] + depth[y] << endl;
    }
    return 0;
}
