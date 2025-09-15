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

ll op(ll a, ll b) { return a+b; }
ll e() { return 0; }

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> jA, j2A;
    rep(i,N) {
        jA.push_back(i * A[i]);
        j2A.push_back(i*i*A[i]);
    }
    segtree<ll, op, e> s(A), sA(jA), s2A(j2A);
    while(Q--) {
         ll l, r; cin >> l >> r;
         l--, r--;
         ll ans = -1 * s2A.prod(l,r+1) + (r+l) * sA.prod(l,r+1) + (1+r)*(1-l)*s.prod(l,r+1);
         cout << ans << endl;
    }
    return 0;
}
