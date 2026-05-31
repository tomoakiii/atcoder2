// https://atcoder.jp/contests/abc221/tasks/abc221_e

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef modint998244353 mint;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
/* ---------------------------------------
 [How to]
 Get max value in range l to r
 LS.prod(l,r+1);

 Add x in range l to r
 LS.apply(l,r+1,x);
--------------------------------------- */
using S = mint;
using F = mint;
S op(S l, S r) { return l+r; }
S e() { return 0; }
S mapping(F l, S r) { return r *= l; }
F composition(F l, F r) { return l*r; }
F id() { return 1; }

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
    rep(i,N) sort(uv[i].begin(),uv[i].end());
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<mint>(N, 0));
    LS.set(0,1);
    rep(i,N) {
        for(auto nx: uv[i]) {
            auto sm = LS.prod(i,nx+1);
            LS.apply(nx+1,N,2);
            LS.set(nx, LS.get(nx)+sm);
        }
    }
    cout<<LS.get(N-1).val()<<endl;
    return 0;
}