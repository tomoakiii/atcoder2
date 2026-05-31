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
    ll N,M; cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    rep(i,N) cin >> x[i] >> y[i] >> z[i];
    ll ans = 0;
    rep(i,2) rep(j,2) rep(k,2) {
        vector<ll> v(N);
        rep(t,N) {
            v[t] = (i ? x[t] : -x[t]) + (j ? y[t] : -y[t]) + (k ? z[t] : -z[t]);
        }
        ll sm = 0;
        sort(v.rbegin(), v.rend());
        rep(t,M) sm += v[t];
        chmax(ans, sm);
    }
    cout << ans << endl;
    return 0;
}