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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    vector<mint> dp(3002, 0);
    for(int k=A[0]; k<=B[0]; k++) dp[k] = 1;
    rep(i,3001) dp[i+1] += dp[i];
    for(int j=1; j<N; j++) {
        vector<mint> dp_new(3002, 0);
        for(int k=A[j]; k<=B[j]; k++) dp_new[k] = dp[k];
        rep(i,3001) dp_new[i+1] += dp_new[i];
        swap(dp, dp_new);
    }
    cout<<dp[B[N-1]].val()<<endl;
    return 0;
}