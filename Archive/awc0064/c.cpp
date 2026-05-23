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
    ll N,M;
    cin >> N >> M;
    vector<ll> dp(M+1,-INF);
    dp[0]=0;
    rep(i,N) {
        auto dp_new = dp;
        ll r,t; cin>>r>>t;
        rep(j,M) {
            if(j+t>M) break;
            chmax(dp_new[j+t], dp[j] + r);
        }
        swap(dp,dp_new);
    }
    ll ans=0;
    rep(i,M+1) chmax(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}