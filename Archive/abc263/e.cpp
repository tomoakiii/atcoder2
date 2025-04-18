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
    vector<ll> A(N-1);
    rep(i,N-1) cin>>A[i];
    vector<mint> dp(N);
    vector<mint> S(N+1);
    for(int i=N-2; i>=0; i--) {
        dp[i] = 1 + (1 + S[i+1] - S[i+A[i]+1])/A[i];
        S[i] = dp[i] + S[i+1];
    }
    cout << dp[0].val() << endl;
    
    return 0;
}