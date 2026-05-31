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
    ll D,G; cin >> D >> G;
    vector<ll> P(D), C(D);
    ll ans = INF;
    vector<ll> dp(1<<12);
    vector<ll> S(1<<12);
    vector<ll> F(D);
    vector<ll> sc(D);
    rep(i,D) {
        sc[i] = (i+1)*100;
        cin>>P[i]>>C[i];
        ll x = (G+sc[i]-1)/sc[i];
        if(x<=P[i]) chmin(ans,x);
        ll fl = P[i]*sc[i] + C[i];
        if(fl >= G) chmin(ans, P[i]);
        S[1<<i] = fl;
        dp[1<<i] = P[i];
        F[i] = fl;
    }
    if(ans < INF) {
        cout << ans << endl;
        return 0;
    }
    rep(k,1<<D) {
        rep(i,D) {
            if(k>>i & 1) continue;
            if(S[k] >= G) continue; // overkill
            ll k2 = k | 1<<i;
            dp[k2] = dp[k] + P[i];
            S[k2] = S[k] + F[i];
            if(S[k2] >= G) {
                ll x = (G-S[k]+sc[i]-1)/sc[i];
                if(x>P[i]) x=P[i];
                chmin(ans, dp[k] + x);
            }
        }
    }
    cout << ans << endl;
    return 0;
}