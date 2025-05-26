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
    int T;
    cin>>T;
    while(T--) {
        int N,K;
        cin >> N >> K;
        int dg;
        vector<int> lmt(61);        
        rep(i,61) {
            lmt[i] = N%2;
            N/=2;
            if(N==0) {
                dg = i;
                break;
            }
        }
        vector dp(dg+1, vector(K+1, vector<mint>(2, 0)));        
        dp[dg][1][0] = 1;
        for(int p=dg-1; p>=0; p--) {
            rep(k, K) {
                if(lmt[p] == 0) {
                    dp[p][k][0] += dp[p+1][k][0]*2;
                    dp[p][k][1] += dp[p+1][k][1]*2;
                    if(nm[p+1][k][1]) dp[p][k+1][1] += dp[p+1][k][1]*2 + 1;
                } else {
                    dp[p][k][1] += dp[p+1][k][0]*2;
                    dp[p][k][1] += dp[p+1][k][1]*2; // 0を入れる場合
                    dp[p][k+1][1] += dp[p+1][k][1]*2 + 1; 
                    dp[p][k+1][0] += dp[p+1][k][0]*2 + 1; 
                }
            }
            if(lmt[p] == 0) {
                dp[p][K][1] += dp[p+1][K][1] * 2;
                dp[p][K][0] += dp[p+1][K][0] * 2;
            } else {
                dp[p][K][1] += dp[p+1][K][1] * 2;
                dp[p][K][1] += dp[p+1][K][0] * 2;
            }            
        }

        mint ans = dp[0][K][0] + dp[0][K][1];
        cout << ans.val() << endl;
    }
    return 0;
} 