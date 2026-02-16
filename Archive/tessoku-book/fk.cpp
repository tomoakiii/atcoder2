//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp
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
typedef modint1000000007 mint;
int main() {
    ll N,P; cin>>N>>P;
    if(P == 0) {
        ll zn = 0;
        rep(i,N) {
            ll a; cin>>a; mint x = a;
            if(x.val() == 0) zn++;
        }
        cout << zn * (zn-1) / 2 + zn * (N-zn) << endl;
        return 0;
    }
    map<ll,ll> mp;
    rep(i,N) {
        ll a; cin>>a; mint x = a;
        if(x.val() > 0) mp[x.val()]++;
    }
    ll ans = 0;
    for(auto [y, c]: mp) {
        mint f = mint(P)/mint(y);
        if(f.val() == y) ans += c * (c-1);
        else ans += c * mp[f.val()];
    }
    cout << ans/2 << endl;
    return 0;
}