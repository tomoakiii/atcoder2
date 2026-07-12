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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];

    vector dp(K+1, vector<ll>(2,-INF));
    dp[0][0] = 0;
    rep(i,N){
        vector dp2(K+1, vector<ll>(2,-INF));
        rep(k,K+1){
            chmax(dp2[k][1], dp[k][1] + B[i]);
            chmax(dp2[k][0], dp[k][0] + A[i]);
            chmax(dp2[k][0], dp[k][1] + A[i]);
        }
        for(int k=0; k<K; k++){
            chmax(dp2[k+1][1], dp[k][0] + B[i]);
        }
        swap(dp,dp2);
    }
    ll ans=0;
    rep(k,K+1){
        chmax(ans, max(dp[k][0], dp[k][1]));
    }
    cout<<ans<<endl;
    return 0;
}