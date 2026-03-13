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
    ll N,a,b;
    cin >> N>>a>>b;
    ll M = 1000;
    vector dp(M+1, vector(2, vector<ll>(2)));
    dp[1][0][0] = a/2; // from a to a
    dp[1][0][1] = b/2; // a to b
    dp[1][1][0] = a; // b to a
    dp[1][1][1] = b; // b to b
    for(int i=1; i<M; i++) {
        dp[i+1][0][0] = max(dp[i][0][0] + dp[i][0][0], dp[i][0][1] + dp[i][1][0]);
        dp[i+1][0][1] = max(dp[i][0][0] + dp[i][0][1], dp[i][0][1] + dp[i][1][1]);
        dp[i+1][1][0] = max(dp[i][1][0] + dp[i][0][0], dp[i][1][1] + dp[i][1][0]);
        dp[i+1][1][1] = max(dp[i][1][0] + dp[i][0][1], dp[i][1][1] + dp[i][1][1]);
    }
    ll dp2[2][2];
    dp2[0][0] = a;
    dp2[0][1] = b;
    dp2[1][0] = a;
    dp2[1][1] = b;
    int ind = 1;
    N--;
    while(N) {
        if(N%2==1) {
            ll dp2_new[2][2];
            dp2_new[0][0] = max(dp2[0][0] + dp[ind][0][0], dp2[0][1] + dp[ind][1][0]);
            dp2_new[0][1] = max(dp2[0][0] + dp[ind][0][1], dp2[0][1] + dp[ind][1][1]);
            dp2_new[1][0] = max(dp2[1][0] + dp[ind][0][0], dp2[1][1] + dp[ind][1][0]);
            dp2_new[1][1] = max(dp2[1][0] + dp[ind][0][1], dp2[1][1] + dp[ind][1][1]);
            swap(dp2, dp2_new);
        }
        ind++;
        N/=2;
    }
    cout<<max(max(dp2[0][0],dp2[0][1]), max(dp2[1][0],dp2[1][1]))<<endl;
    return 0;
}