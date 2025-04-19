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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<mint> dp(K+1);
    dp[0] = 1;
    rep(i,N){
        vector<mint> ndp(K+1);
        for(int j=1; j<=M; j++) {
            for(int k=0; k<=K; k++)  {
                if(j+k > K) continue;
                ndp[k+j] += dp[k];
            }
        }
        swap(ndp, dp);
    }
    mint ans = 0;
    rep(i,K+1) {
        ans += dp[i];
    }
    cout << ans.val() << endl;
    return 0;
}