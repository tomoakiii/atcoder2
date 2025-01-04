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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N), Y(N);

    ll xm1=0, xm2=0, ym1=0, ym2=0;
    rep(i,N) {
        ll x, y;
        cin >> x >> y;
        X[i] = x+y;
        Y[i] = x-y;
        chmax(xm1, X[i]);
        chmax(xm2, -X[i]);
        chmax(ym1, Y[i]);
        chmax(ym2, -Y[i]);
    }
    rep(i,Q) {
        ll ans = -1;
        int q;
        cin >> q;
        q--;
        chmax(ans, xm2 + X[q]);
        chmax(ans, xm1 - X[q]);
        chmax(ans, ym2 + Y[q]);
        chmax(ans, ym1 - Y[q]);
        cout << ans << endl;
    }

    return 0;
}