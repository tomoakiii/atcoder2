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
    vector<ll> T(N);    
    rep(i,N) cin>>T[i];
    sort(T.begin(), T.end());
    ll mxT = T[T.size()-1];
    ll M = mxT * N + 1;
    vector<ll> dp(M,INF);
    dp[0] = 0;
    rep(i,N) {
        vector<ll> dp_new(M,INF);
        rep(j,M) {     
            chmin(dp_new[j], dp[j] + T[i]);
            if(j+T[i]<M) chmin(dp_new[j+T[i]], dp[j]);
        }
        swap(dp, dp_new);
    }
    ll ans = INF;
    rep(i,M) {
        chmin(ans, max(i,dp[i]));        
    }
    cout<<ans<<endl;
    return 0;
}