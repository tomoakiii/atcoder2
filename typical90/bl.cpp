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
S op(S l, S r) {return max(l, r);}
S e() {return 0;}
S mapping (F l, S r) {return r+=l;}
F composition (F l, F r) {return l+r;}
F id() {return 0;}



int main(){
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    ll ans = 0;
    rep(i,N) cin>>A[i];
    rep(i,N-1) ans += abs(A[i+1]-A[i]);
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);

    while(Q--) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--, r--;
        ll t = 0;
        if(l > 0) t -= abs(LS.get(l) - LS.get(l-1));
        if(r < N-1) t -= abs(LS.get(r+1) - LS.get(r));
        LS.apply(l, r+1, v);
        if(l > 0) t += abs(LS.get(l) - LS.get(l-1));
        if(r < N-1) t += abs(LS.get(r+1) - LS.get(r));
        ans += t;
        cout << ans << endl;
    }
    return 0;
}