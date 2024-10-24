#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
    ll N, M;
    cin >> N >> M;
    vector dp(N, vector<mint>(2, 0));
    dp[0][0] = M;
    for(int i=1; i<N; i++){
        dp[i][0] += dp[i-1][1];
        dp[i][1] += dp[i-1][1] * (M-2);
        dp[i][1] += dp[i-1][0] * (M-1);
    }
    
    cout << dp[N-1][1].val() << endl;
    return 0;
}