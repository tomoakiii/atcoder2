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

struct S {
    mint s2=0, s1=0;
    ll sz=1;
};

using F = mint;

S op(S a, S b) {
    return { (a.s2 + b.s2), (a.s1 + b.s1), (a.sz + b.sz) };
}

S e() { return {0, 0, 0}; }

S mapping(F f, S x) {
    mint new_s2 = (x.s2 + 2 * f * x.s1 + f * f * x.sz);
    mint new_s1 = (x.s1 + f * x.sz);
    return { new_s2, new_s1, x.sz };
}

F composition(F f, F g) { return (f + g); }
F id() { return 0; }

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<S> A(N);
    vector<ll> B(N);


    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);

    vector<ll> ans(Q);
    rep(i,Q) {
        int l,r; ll a;
        cin>>l>>r>>a;
        l--,r--;

        LS.apply(l,r+1,a);
        S x = LS.prod(l,r+1);

        mint y = x.s1*x.s1 - x.s2;
        y /= 2;
        ans[i] = y.val();

    }
    rep(i,Q) cout<<ans[i]<<endl;
    return 0;
}