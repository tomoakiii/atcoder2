
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<int> grp(N);
    vector<int> B(N);
    int sm = 0;
    rep(i,N){
        int a, b;
        cin >> a >> b;
        a--;
        grp[i] = a;
        B[i] = b;
        sm += B[i];
    }
    if (sm%3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    int tgt = sm/3;
    vector dp(N+1, vector(tgt+1, vector<int>(tgt+1, INFi)));
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, tgt+1) {
            rep(k, tgt+1) {
                    if(j+B[i] <= tgt){
                        if(grp[i] != 0) chmin(dp[i+1][j+B[i]][k], dp[i][j][k] + 1);
                        else chmin(dp[i+1][j+B[i]][k], dp[i][j][k]);
                    }
                    if(k+B[i] <= tgt) {
                        if(grp[i] != 1) chmin(dp[i+1][j][k+B[i]], dp[i][j][k] + 1);
                        else chmin(dp[i+1][j][k+B[i]], dp[i][j][k]);
                    }
                    if(grp[i] != 2) chmin(dp[i+1][j][k], dp[i][j][k] + 1);
                    else chmin(dp[i+1][j][k], dp[i][j][k]);                    
            }
        }
    }
    if (dp[N][tgt][tgt] >= INFi) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[N][tgt][tgt] << endl;
    return 0;
}