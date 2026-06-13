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
using S = ll;
using F = ll;
S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F l, S r) { return r += l; }
F composition(F l, F r) { return l + r; }
F id() { return 0; }


void solve(){
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(N, 0));

    for(int i=N-2;i>=0;i--){
        if(A[i] < A[i+1]) {
            LS.add(i,A[i+1]-A[i]);
            continue;
        }
        else {
            ll d=A[i]-A[i+1];
        }
    }
}


int main(){
    ll T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}