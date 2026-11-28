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
typedef modint998244353 mint;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector dp(K+1, vector<mint>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i,N-1){
        vector dp2(K+2, vector<mint>(2));
        rep(k,K+1){
            if(A[i+1] == A[i]) dp2[k+1][0] += dp[k][0];
            else dp2[k][0] += dp[k][0];
            if(A[i+1] == B[i]) dp2[k+1][0] += dp[k][1];
            else dp2[k][0] += dp[k][1];
            if(B[i+1] == A[i]) dp2[k+1][1] += dp[k][0];
            else dp2[k][1] += dp[k][0];
            if(B[i+1] == B[i]) dp2[k+1][1] += dp[k][1];
            else dp2[k][1] += dp[k][1];
        }
        swap(dp,dp2);
    }
    cout << (dp[K][0]+dp[K][1]).val() << endl;
    return 0;
}