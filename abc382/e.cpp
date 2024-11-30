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
    int N, X;
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
    vector<double> E(X+1, -1);
    double y = 1/(1-dp[N][0]);
    E[0] = 0;
    E[1] = y; 
    auto f = [&](auto f, int x)->double{
        if(E[x] > -0.1) {
            return E[x];
        }
        double sm = 0;
        for(int i=1; i<=min(N, x); i++) {
            int r = x-i;
            if(E[r] < 0) E[r] = f(f, r);
            sm += dp[N][i] * E[r];
        }
        sm = y * (1 + sm);
        E[x] = sm;
        return sm;
    };
    printf("%.12f\n", f(f, X));
    return 0;
}