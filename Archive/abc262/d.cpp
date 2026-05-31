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

    mint ans = 0;
    for(ll j=1; j<=N; j++) {
        vector dp(N+1, vector(N+1, vector<mint>(N, 0)));
        dp[0][0][0] = 1;
        for(ll i=1; i<=N; i++) {            
            for(ll k=0; k<=i; k++) {
                for(ll p=0; p<j; p++) {                    
                    dp[i][k][p] += dp[i-1][k][p];
                    ll r = (p+A[i-1])%j;
                    if(k > 0) dp[i][k][r] += dp[i-1][k-1][p];
                }
            }
        }
        ans += dp[N][j][0];
    }


    cout << ans.val() << endl;
    return 0;
}