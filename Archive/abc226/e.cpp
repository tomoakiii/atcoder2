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
typedef modint998244353 mint;
int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    dsu UF(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        //uv[v].emplace_back(u);
        UF.merge(u,v);
    }
    vector<bool> visit(N);
    mint ans = 1;
    for(auto g: UF.groups()) {
        ll lcnt = 0;
        for(auto vg: g) lcnt += uv[vg].size();
        if(lcnt == g.size()) ans *= 2;
        else ans = 0;
    }
    cout<<ans.val()<<endl;
    
    return 0;
}