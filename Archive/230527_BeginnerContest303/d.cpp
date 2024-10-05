#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll X,Y,Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    ll N = S.size();
    vector dp(N+1, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = Z;
    ll llZ = min(Z+X, Z+Y);
    ll llX = min(X, Z+Y+Z);
    ll llY = min(Y, Z+X+Z);
    for(int i=1; i<=N; i++) {
        ll a,b,c;
        if(S[i-1] == 'A'){
            dp[i][0] += min(dp[i-1][0] + llY, dp[i-1][1] + llZ);
            dp[i][1] += min(dp[i-1][0] + llZ, dp[i-1][1] + llX);
        } else{
            dp[i][0] += min(dp[i-1][0] + llX, dp[i-1][1] + llZ);
            dp[i][1] += min(dp[i-1][0] + llZ, dp[i-1][1] + llY);
        }        
    }
    cout << min(dp[N][0], dp[N][1]) << endl;
    return 0;
}