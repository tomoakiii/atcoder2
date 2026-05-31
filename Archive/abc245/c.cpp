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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    vector dp(N, vector<ll>(2));
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    rep(i,N-1) {
        dp[i+1][0] = (abs(dp[i][0]-A[i+1])<=K || abs(dp[i][1]-A[i+1])<=K)?A[i+1]:INF;
        dp[i+1][1] = (abs(dp[i][0]-B[i+1])<=K || abs(dp[i][1]-B[i+1])<=K)?B[i+1]:INF;
    }
    if(dp[N-1][0]==A[N-1] || dp[N-1][1]==B[N-1]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}