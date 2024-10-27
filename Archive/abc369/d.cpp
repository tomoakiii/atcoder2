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
    vector<ll> A(N, 0);
    rep(i,N) cin>>A[i];
    vector dp(N, vector<ll>(2));
    bool f=false;
    dp[0][0] = A[0];
    dp[0][1] = 0;
    for(int i=1; i<N; i++){
        dp[i][1] = max(dp[i-1][0] + 2*A[i], dp[i-1][1]);
        dp[i][0] = max(dp[i-1][1] + A[i], dp[i-1][0]);
    }
    cout << max(dp[N-1][0], dp[N-1][1]) << endl;
    return 0;
}