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
typedef pair<ll,ll> pll;
int main(){
    ll W, N;
    cin >> W >> N;
    vector<ll> L(N), R(N), V(N);
    rep(i,N) {
        cin>>L[i]>>R[i]>>V[i];
    }
    vector<pll> dp(W+1, {-INF,-INF});
    dp[0] = {0, 0};
    rep(i,N) {
        vector old = dp;
        pll j = {L[i], R[i]};
        rep(k, W+1) {
            if (k + L[i] > W) break;
            chmax(dp[k + j], old[k] + j);
        }
    }
    if(dp[W] < 0) cout << -1 << endl;
    else cout << dp[W] << endl;
    return 0;
}