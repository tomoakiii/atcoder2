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
    vector<pair<int,int>> LR(N);
    vector<int> cnt(N);

    auto dfs = [&](auto dfs, int cur, int pre, int p)->int{
        cnt[cur] = 1;
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            cnt[cur] += dfs(dfs, nx, cur, R[cur]);
        }
        return cnt[cur];
    };
    dfs(dfs,0,-1,1);
    return 0;
}