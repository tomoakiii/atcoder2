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
    ll X, K;
    cin >> X >> K;
    ll ans = 0;
    ll k = 1;
    rep(p, K) {
        ll r = (X % (k*10));
        r /= k;
        X -= r*k;
        if (r >= 5) {
            X += k*10;
        }
        k *= 10;
    }
    cout << X << endl;
    return 0;
}