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
    ll N, X;
    cin >> N >> X;
    vector<double> P(N);
    rep(i,N) {
        cin>>P[i];
        P[i] /= 100;
    }
    vector dp(N+1, vector<double>(N+1, 0));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, N) {
            dp[i+1][j] += dp[i][j] * (1-P[i]);
            dp[i+1][j+1] += dp[i][j] * P[i];
        }
    }

    auto f = [&](auto f, int cnt, int x, double p)->double{
        if(x >= X) {
            return p*cnt;
        }
        cnt += dp[N][0] / (1 - dp[N][0]);
        double ans = 0;
        rep(i, N) {
            ans += f(f, cnt+1, x+i+1, p * dp[N][i+1]);
        }
        return ans;
    };
    printf("%.12f\n", f(f, 0, 0, 1));
    return 0;
}