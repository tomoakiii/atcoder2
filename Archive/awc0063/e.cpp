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
 Update value in range l to r
 A[i] = a * A[i] + b

 Add value x at range l to r
 LS.apply(l, r+1, x) ;
--------------------------------------- */
using F = ll;
struct S{
  ll l,r,n;
  S(ll l, ll r, ll n): l(l),r(r),n(n){}
};
S op(S a, S b){
    if(b.l==0) return a;
    if(a.r==0) return b;
    if(a.r == b.l) {
        return S(a.l, b.r, a.n+b.n-1);
    } else {
        return S(a.l, b.r, a.n+b.n);
    }
}
S e(){ return S(0,0,0); }
S mapping(F f, S x){
    if(f==0) return x;
    return S(f,f,1);
}
F composition(F f, F g){
    if(f==0) return g;
    else return f;
}
F id(){ return 0; }


int main(){
  ll N,Q; cin>>N>>Q;
  vector<S> vec(N, S(0,0,0));
  rep(i,N) {
    ll c; cin>>c;
    vec[i] = S(c,c,1);
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> LS(vec);
  while(Q--) {
    int op; cin>>op;
    ll L,R; cin>>L>>R; L--,R--;
    if(op==1) {
        ll x; cin>>x;
        LS.apply(L,R+1,x);
    } else {
        cout << LS.prod(L,R+1).n << endl;
    }
  }
  return 0;
}
