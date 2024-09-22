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
typedef modint998244353 mint;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N, 0);
    rep(i,N) cin >> A[i];
    vector<ll> S(N+1, 0);
    rep(i,N) {
        S[i+1] = A[i] + S[i];
    }
    vector<mint> dp(N+1);
    dp[0] = 1;
    mint Sdp = 1;
    map<ll, mint> dpSum;
    dpSum[0] = 1;

    for(int i=1; i<=N; i++) {
        dp[i] = Sdp;
        ll key = S[i]-K;
        if(dpSum.count(key) != 0) {
            dp[i] = dp[i] - dpSum[key];
        }
        dpSum[S[i]] = dpSum[S[i]] + dp[i].val();
        Sdp += dp[i];
    }
    cout << dp[N].val() << endl;
    return 0;
}