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
    string S;
    cin >> S;
    vector dp(N, vector<ll>(3, -INF));
    char last='X';

    auto f = [&](char x, char y) -> int {
        int ret = 1;
        if (x == 'R' && y == 'S') ret = -1;
        if (x == 'S' && y == 'P') ret = -1;
        if (x == 'P' && y == 'R') ret = -1;
        if (x == y) ret = 0;
        return ret;
    }; // x win y --> 1 ///  x lost againt to y --> -1
    
    char RSP[3] = {'R', 'S', 'P'};
    rep(k,3){
        if (f(S[0], RSP[k]) == 1) dp[0][k] = 1;
        if (f(S[0], RSP[k]) == 0) dp[0][k] = 0;
    }
    
    for(int i=1; i<N; i++){
        rep(j,3) { // last scan
            rep(k,3) { // current scan
                if (j == k) continue;
                if (f(S[i], RSP[k]) == 1) dp[i][k] = max(dp[i-1][j] + 1, dp[i][k]);
                if (f(S[i], RSP[k]) == 0) dp[i][k] = max(dp[i-1][j], dp[i][k]);
            }
        }
    }
    ll mx = 0;
    rep(k,3){
        mx = max(dp[N-1][k], mx);
    }

    cout << mx << endl;
    return 0;
}