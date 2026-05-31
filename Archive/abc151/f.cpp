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
    ll N;
    cin >> N;
    vector<ll> X(N),Y(N);
    rep(i,N) cin>>X[i]>>Y[i];

    ll mx = 0;
    rep(i,N) rep(j,N) {
        ll x = X[i]-X[j];
        ll y = Y[i] - Y[j];
        chmax(mx, x*x+y*y);
    }

    long double ans = mx;
    ans = sqrtl(ans);
    printf("%.20Lf\n", ans/2);
    return 0;
}