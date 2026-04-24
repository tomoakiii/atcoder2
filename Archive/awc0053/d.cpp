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

/* ---------------------------------------
 [How to]
 Overwrite by value x in range l to r
 LS.apply(l,r+1,x);

 Get sum in range l to r
 S gt = LS.prod(l, r+1)

 Get value at index i
 LS.get(i).value.val()
--------------------------------------- */
struct S{
    ll value=0;
    int size=1;
};
S op(S a, S b){ return S(a.value+b.value, a.size+b.size); }
S e(){ return S(0, 0); }
using F = ll;
S mapping(F f, S x){
    if(f!=INF) x.value = f * x.size;
    return x;
}
F composition(F f, F g){ return (f!=INF? f : g); }
F id(){ return INF; }

int main(){
    ll N,M;
    cin >> N >> M;
    vector<S> v(N);
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(v);
    rep(i,M) {
        int l,r; cin>>l>>r; l--,r--;
        ll c; cin>>c;
        LS.apply(l,r+1,c);
    }
    rep(i,N) {
        cout<<LS.get(i).value<<" \n"[i==N-1];
    }
    return 0;
}