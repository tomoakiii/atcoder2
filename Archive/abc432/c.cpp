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
    ll N, X, Y; cin>>N>>X>>Y;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll D = Y-X;
    ll mnM = INF;
    rep(i,N) chmin(mnM, Y*A[i]);
    ll ans = 0;
    rep(i,N) {
        ll P = Y*A[i] - mnM;
        if(P%D != 0) {
            cout << -1 << endl;
            return 0;
        }
        ll a = P/D;
        ll b = A[i] - a;
        if(a < 0 || a > A[i] || b < 0 || b > A[i] || a * X + b* Y != mnM) {
            cout << -1 << endl;
            return 0;
        }
        ans += b;
    }
    cout << ans << endl;
    return 0;
}