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
    ll ans = 0;
    auto dfs = [&] (auto dfs, int cur, ll visit) -> void{
        if(visit == (1 << N) - 1) {
            ans ++;
            return ;
        }        
        for(auto nx: uv[cur]) {
            if(visit >> nx & 1) continue;
            ll v2 = visit | 1<<nx;
            dfs(dfs, nx, v2);            
        }
    };
    dfs(dfs, 0, 1);
    cout << ans << endl;
    return 0;
}