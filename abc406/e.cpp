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
        vector dp(dg+1, vector<vector<pair<mint, ll>>>(K+1, vector<pair<mint, ll>>(2)));
        dp[dg][1][0] = {1, 1}; // 1 is matching
        for(int p=dg-1; p>=0; p--) {
            if(lmt[p] > 0) {
                dp[p][K][1].first = 2*(dp[p+1][K][1].first+dp[p+1][K][0].first);
                dp[p][K][1].second = dp[p+1][K][1].second+dp[p+1][K][0].second;
            } else {
                dp[p][K][0].first = 2*dp[p+1][K][0].first;
                dp[p][K][0].second = dp[p+1][K][0].second;
                dp[p][K][1].first = 2*dp[p+1][K][1].first;
                dp[p][K][1].second = dp[p+1][K][1].second;
            }
            rep(k, K) {
                if(lmt[p] > 0) {
                    dp[p][k+1][1].first += 2*dp[p+1][k][1].first + dp[p+1][k][1].second; // smaller is going smaller
                    dp[p][k+1][1].second += dp[p+1][k][1].second; // smaller is going smaller
                    dp[p][k+1][0].first += 2*dp[p+1][k][0].first + dp[p+1][k][0].second; // match is going match
                    dp[p][k+1][0].second += dp[p+1][k][0].second; // 
                    dp[p][k][1].first += 2*(dp[p+1][k][1].first + dp[p+1][k][0].first); // not 1 lower
                    dp[p][k][1].second += dp[p+1][k][1].second + dp[p+1][k][0].second;
                } else {
                    dp[p][k+1][1].first += 2*dp[p+1][k][1].first + dp[p+1][k][1].second; // match goes over
                    dp[p][k+1][1].second += dp[p+1][k][1].second; // smaller is going smaller
                    dp[p][k][1].first += 2*dp[p+1][k][1].first;
                    dp[p][k][1].second += dp[p+1][k][1].second; // smaller is going smaller
                    dp[p][k][0].first += 2*dp[p+1][k][0].first; // not 1 keep
                    dp[p][k][0].second += dp[p+1][k][0].second; // smaller is going smaller
                }
            }
            
        }
        mint ans = dp[0][K][0].first + dp[0][K][1].first;
        cout << ans.val() << endl;
    }
    return 0;
}