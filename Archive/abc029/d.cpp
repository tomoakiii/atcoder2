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

int main(){
    ll N; cin>>N;
    ll p = 1;
    ll p2 = 10;
    ll ans = 0;
    rep(i,10) {
        ll a = N/p2;
        ans += a * p;
        ll r = N%p2;
        r = max(0ll, r-(p-1));
        chmin(r, p);
        ans += r;
        p *= 10;
        p2 *= 10;
    }
    cout << ans << endl;
    return 0;
}