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
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tiii;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(46), B(46), C(46);
    ll a;
    rep(i,N) {
        cin >> a;
        A[a%46]++;
    }
    rep(i,N) {
        cin >> a;
        B[a%46]++;
    }
    rep(i,N) {
        cin >> a;
        C[a%46]++;
    }
    ll ans = 0;
    rep(i, 46) rep(j, 46) {
        ll k = (i + j) % 46;
        ll p = 46 - k;
        if (p == 46) p = 0;
        ans += A[i] * B[j] * C[p];
    }
    cout << ans << endl;
    return 0;
}