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

using S = int;
using F = int;
S op(S l, S r) {return max(l, r);}
S e() {return 0;}
S mapping (F l, S r) {return r+=l;}
F composition (F l, F r) {return l+r;}
F id() {return 0;}


int main(){
    int N;
    cin >> N;    
    
    const ll M = 500005;
    vector<int> o(M);
    rep(i,M) o[i] = i;
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(o);
    rep(t, N){
        ll l, r;
        cin >> l >> r;
        r++;
        auto L = LS.max_right(0, [&](int x) { return x < l; });
        auto R = LS.max_right(0, [&](int x) { return x < r; });
        LS.apply(L, R, 1);
    }
    ll Q;
    cin>>Q;
    while(Q--) {
        ll x;
        cin >> x;        
        cout << LS.get(x) << endl;
    }
    
    return 0;
}