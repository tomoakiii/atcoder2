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

void solve(){
    int N, K; cin>>N>>K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector dp(N+1, vector<ll>(2,INF));
    dp[0][0] = 0;
    dp[1][1] = A[0]; // fill
    dp[2][1] = A[0]+A[1];
    dp[2][0] = A[0];
    for(int i=2; i<N; i++) {
        chmin(dp[i+1][1], dp[i-1][1] + A[i]);
        chmin(dp[i+1][1], dp[i][1] + A[i]);
        chmin(dp[i+1][1], dp[i][0] + A[i]);
        dp[i+1][0] = dp[i][1];
    }
    ll ans=INF;
    ll sm=0;
    for(int i=K; i<N; i++){
        ll p=dp[i+1][1]-dp[i-K][0];
        if(p>0) chmin(ans,p);
        ll q=dp[i+1][1]-dp[i-K][1];
        if(q>0) chmin(ans,q);
        ll r=dp[i+1][1]-dp[i-K+1][1];
        if(r>0) chmin(ans,r);
    }
    cout<<ans<<endl;
}


int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}