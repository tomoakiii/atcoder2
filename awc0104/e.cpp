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
struct S {
    ll a=0, b=0;
};
struct F {
    ll a=0, b=0;
};

S op(S a, S b) {
    S c;
    if(a.b>=a.a){
        c.b += a.b;
        c.a += a.a;
    }
    if(b.b>=b.a) {
        c.b += b.b;
        c.a += b.a;
    }
    return c;
}
S e() { return {0, 0}; }
S mapping(F f, S x) {
    x.a += f.a;
    x.b += f.b;
    return x;
}
F composition(F f, F g) {
    f.a += g.a;
    f.b += g.b;
    return f;
}
F id() { return {0, 0}; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<S> A(N);
    rep(i,N)  cin >> A[i].a >> A[i].b;
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);
    while(Q--){
        ll qrt,l,r,x;
        cin>>qrt>>l>>r>>x;
        l--;
        if(qrt==2){
            F s; s.a=x;
            LS.apply(l,r,s);
        } else {
            F s; s.b=x;
            LS.apply(l,r,s);
        }
        S out = LS.all_prod();
        cout << out.b - out.a << endl;
    }
    return 0;
}