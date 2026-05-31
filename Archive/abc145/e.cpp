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
    ll N,T;
    cin >> N >> T;
    vector<ll> A(N),B(N);
    ll mx = 0;
    rep(i,N) {
        cin>>A[i]>>B[i];
        chmax(mx, B[i]);
    }
    vector<pair<ll,ll>> dp(T);
    ll ans = 0;
    rep(i,N) {
        auto dp_new = dp;
        rep(j,T) {
            {
                ll v = dp[j].first;
                ll sb = max(dp[j].second,B[i]);
                if(dp_new[j].first + dp_new[j].second < v + sb ) {
                    dp_new[j] = {v,sb};
                }
            }
            if(j+A[i]>=T) continue;
            {
                ll v = dp[j].first+B[i];
                ll sb = dp[j].second;
                if(dp_new[j+A[i]].first + dp_new[j+A[i]].second < v + sb ) {
                    dp_new[j+A[i]] = {v,sb};
                }
            }
        }
        swap(dp, dp_new);
    }
    rep(i,T) {
        chmax(ans, dp[i].first + dp[i].second);
    }
    cout << ans << endl;
    return 0;
}