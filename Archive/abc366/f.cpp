#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> AB(N);
    rep(i,N) cin>>AB[i].first>>AB[i].second;
    sort(AB.begin(), AB.end(), [&](pair<int, int>ab1, pair<int, int>ab2)->bool {
        return ab2.first*(ab1.first+ab1.second)+ab2.second > ab1.first*(ab2.first*1+ab2.second)+ab1.second;
    });
    vector dp(N+1, vector<ll>(K+1));
    dp[0][0] = 1;
    for(int i=1; i<=N; i++){
        dp[i][0] = 1;
        for(int j=1; j<=min(i,K); j++){
            dp[i][j]=max(dp[i-1][j], AB[i-1].first*dp[i-1][j-1]+AB[i-1].second);
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}