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
    ll N, Q;
    cin >> N >> Q;
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> P(N);
    rep(i,Q){
        ll p, x; cin>>p>>x;
        p--;
        P[p] += x;
    }
    auto dfs = [&](auto dfs, int cur, int pre, ll s)->void{
        P[cur] += s;
        for(auto nx: uv[cur]){
            if(nx == pre) continue;
            dfs(dfs, nx, cur, P[cur]);
        }
    };
    dfs(dfs, 0, -1, 0);
    rep(i,N) cout<<P[i]<<((i<N)?" ":"\n");
    return 0;
}