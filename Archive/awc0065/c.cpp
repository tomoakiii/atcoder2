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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector dp(N,vector<ll>(2));
    dp[0][0]=0;
    dp[0][1]=A[0];
    if(N>1) {
        dp[1][0]=A[0];
        dp[1][1]=A[1];
    }
    for(int i=2; i<N; i++) {
        dp[i][1] = dp[i-1][0]+A[i];
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[N-1][0],dp[N-1][1])<<endl;
    return 0;
}