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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> dp(K+1);
    dp[0] = 1;
    rep(i,N) {
        for(int j=K; j>=0; j--) {
            if(j+A[i] > K) continue;
            dp[j+A[i]] += dp[j]>0;
        }
    }
//    rep(j,K+1) cerr<<j<<";"<<dp[j]<<endl;
    for(int i=K; i>=0; i--)  if(dp[i]!=0) {
        cout<<i<<endl;
        return 0;
    }
    return 0;
}