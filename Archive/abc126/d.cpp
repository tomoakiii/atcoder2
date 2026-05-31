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
    cin >> N;
    M = N-1;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    vector<int> col(N);
    auto dfs = [&](auto dfs, int cur, int pre, int d)->void{
        col[cur] = d;
        for(auto [nx,w]: uv[cur]) {
            if(nx == pre) continue;
            if(w%2 == 0) dfs(dfs, nx, cur, d);
            else dfs(dfs, nx, cur, (d+1)%2);
        }
    };
    dfs(dfs, 0, -1, 0);
    rep(i,N) cout<<col[i]<<endl;
    return 0;
}