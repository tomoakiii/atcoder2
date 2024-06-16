#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector dp(N+1, vector<ll>(2));
    rep(i, N){
        ll X, Y;
        cin >> X >> Y;
        if (X == 0){
            dp[i+1][0] = max(max(dp[i][0], dp[i][0]+Y), dp[i][1]+Y);
            dp[i+1][1] = dp[i][1];
        } else {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = max(dp[i][0] + Y, dp[i][1]);
        }
    }
    
    cout << max(dp[N][0], dp[N][1]) << endl;
    return 0;
}