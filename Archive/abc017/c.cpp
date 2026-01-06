#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
template <typename T>
inline bool chmax(T& a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T& a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
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

int main(){
    ll N,M;
    cin >> N >> M;
    lazy_segtree<S,op,e,F,mapping,composition,id> ST(vector<ll>(M+1));
    ll sm = 0;
    rep(i,N) {
        int l,r;
        cin>>l>>r;
        l--, r--;
        ll v; cin>>v;
        ST.apply(l,r+1,v);
        sm += v;
    }
    ll ans = 0;
    rep(i,M) {
        ll tmp = sm - ST.get(i);
        chmax(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}