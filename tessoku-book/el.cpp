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

int main() {
    int N,T; cin>>N>>T;
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    vector<int> dist(N, INFi);
    auto dfs = [&](auto dfs, int cur, int pre=-1)->int{
        int ret = 0;
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            dist[nx] = dist[cur] + 1;
            chmax(ret, 1+dfs(dfs, nx, cur));
        }
        dist[cur] = ret;
        return ret;
    };
    dfs(dfs, T-1);
    for(auto d: dist) cout << d << " ";
    cout << endl;
}