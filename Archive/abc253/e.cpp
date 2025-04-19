#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

typedef modint998244353 mint;

int main(){
    int N, M, K;
    cin >> N >> M >> K;    
    vector<mint> dp(M, 1);    
    rep(i,N-1){
        rep(j,M-1) {
            dp[j+1] += dp[j];
        }
        vector<mint> dp_new(M, 0);
        rep(j,M){
            if(K==0) {
                dp_new[j] += dp[M-1];
            } else {
                if(j+K<M) dp_new[j] += dp[M-1] - dp[j+K-1];
                if(j>=K) dp_new[j] += dp[j-K];
            }
        }
        swap(dp_new, dp);
    }
    mint ans = 0;
    rep(j,M) ans += dp[j];
    cout << ans.val() << endl;
    return 0;
}