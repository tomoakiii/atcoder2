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
    vector<int> visit(N);
    vector<int> G;
    auto dfs = [&](auto dfs, int cur)->void{
        visit[cur] = true;
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            dfs(dfs, nx);
        }
        G.push_back(cur);
    };
    rep(i,N) {
        if(visit[i]) continue;
        dfs(dfs, i);
    }

    vector<ll> dp(N);
    dp[G[0]] = 1;
    for(auto g: G) {
        for(auto nx: uv[g]) {
            dp[nx] += dp[g];
        }
    }
    cout<<dp[G[N-1]]<<endl;
    return 0;
}