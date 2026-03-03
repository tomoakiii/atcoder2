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
struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N,Q; cin>>N>>Q;
    std::vector<S> C(N, {0, 1});
    rep(i,N) cin>>C[i].value;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(C);
    while(Q--) {
        int quer; cin>>quer;
        int l,r; cin>>l>>r; l--,r--;
        if(quer==1) {
            ll v; cin>>v;
            seg.apply(l,r+1, v);
        } else {
            cout << seg.prod(l,r+1).value << endl;
        }
    }
    return 0;
}

