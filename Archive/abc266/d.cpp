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
    ll t= 0;
    vector<ll> T(N), X(N), A(N);
    rep(i,N) cin>>T[i]>>X[i]>>A[i];
    vector dp(N+1, vector<ll>(5, -INF));
    dp[0][0] = 0;
    rep(i,N) {
        ll td = T[i] - t;
        t = T[i];
        rep(j,5) for(ll j2 = -td; j2 <= td; j2++) {
            int nx = j+j2;
            if(nx < 0 || nx > 4) continue;
            if(nx == X[i]) chmax(dp[i+1][nx], dp[i][j] + A[i]);
            else chmax(dp[i+1][nx], dp[i][j]);
        }
    }
    ll ans = 0;
    rep(i,5) chmax(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}