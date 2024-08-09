#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector dp(N+1, vector<vector<ll>>(X+2, vector<ll>(N, INF)));
    vector<ll> A(N), B(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
    }
    rep(i, N) dp[i][0][0] = 0;
    rep(i, N) rep(j, X+1) rep(k, N){
        int ni = i+1, nj = j + A[i], nk = k+1;
        dp[ni][j][k] = min(dp[ni][j][k], dp[i][j][k]);
        if (nj > X) {
            nj = X + 1;
        }        
        dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + B[i]);

    }
    ll mx = 0;
    rep(k, N) rep(j, X+1) {
        if (dp[N][j][k] <= Y) mx = k;
    }
    if (mx < N) {
        mx++;
    }
    cout << mx << endl;
    return 0;
}