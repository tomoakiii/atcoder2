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
 Get max value in range l to r
 LS.prod(l,r+1);

 Add x in range l to r
 LS.apply(l,r+1,x);
--------------------------------------- */
using S = ll;
using F = ll;
S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F l, S r) { return r += l; }
F composition(F l, F r) { return l + r; }
F id() { return 0; }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    string T;
    cin>>T;
    vector<ll> A(N);
    rep(i,N){
        if(T[i]=='(') A[i]++;
        else A[i]--;
    }
    rep(i,N-1)A[i+1]+=A[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);
    while(Q--){
        int t; 
    }
    return 0;
}