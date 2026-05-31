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
typedef modint1000000007 mint;
int main(){
    ll N, M;
    cin >> N;
    M = N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector dp(N, vector<mint>(2));
    auto dfs = [&](auto dfs, int cur, int pre=-1) -> void{
        if(uv[cur].size() == 1 && uv[cur][0] == pre) {
            dp[cur][0] = dp[cur][1] = 1;
            return;
        }
        mint totw = 1;
        mint totb = 1;
        for(auto nx: uv[cur]) {
            if(nx==pre) continue;
            dfs(dfs, nx, cur);
            totw *= (dp[nx][0] + dp[nx][1]);
            totb *= dp[nx][0];
        }
        dp[cur][0] = totw;
        dp[cur][1] = totb;
    };
    dfs(dfs, 0);
    mint ans = dp[0][0] + dp[0][1];
    cout << ans.val() << endl;
    return 0;
}