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

int main(){
    ll K;
    cin >> K;
    vector dp(100, vector<ll>(10));
    ll cnt = 0;
    rep(i, 100000) {
        rep(j, 10) {
            if(j-1>=0) dp[i+1][j] += dp[j-1];
            dp[i+1][j] += dp[j];
            if(j+1<=9) dp[i+1][j] += dp[i][j+1];
            cnt += dp[i+1][j];
            if(cnt>=K) break;
        }
        if(cnt>=K) {
            auto f = [&](auto f, int cur, int v, ll rem)->void{
                cout << v << endl;
                if(cur == 0) return;
                if(dp[cur-1]) 
            };         
        }
    }
        
    return 0;
}