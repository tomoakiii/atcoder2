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
    ll N,K;
    cin >> N >> K;
    vector<ll> L(K),R(K);
    rep(i,K) {
        cin>>L[i]>>R[i];
    }    
    vector<mint> dp(5*N);
    dp[1] = 1;
    mint x = 0;
    rep(i,N+2) {
        x += dp[i];
        rep(j,K) {
            dp[i + L[j]] += x;
            dp[i + R[j] + 1] -= x; 
        }
    }
    cout<<dp[N].val()<<endl;
    return 0;
}