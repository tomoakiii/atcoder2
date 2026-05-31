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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<mint> dp(10);
    dp[A[0]%10] = 1;
    rep(i,N-1) {
        vector<mint> dp_new(10);
        rep(j,10){
            dp_new[(A[i+1] + j)%10] += dp[j];
            dp_new[(A[i+1] * j)%10] += dp[j];
        }
        swap(dp, dp_new);
    }
    rep(i,10) cout<<dp[i].val()<<endl;
    return 0;
}