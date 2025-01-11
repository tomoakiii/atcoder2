#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    rep(i,N) {
        cin>>L[i]>>R[i];
        L[i]--, R[i]--;
    }
    vector dp(101, vector<double>(N+1));
    rep(p, 101) dp[p][0] = 1;
    double ans;
    rep(i, N) {
        vector dpN = dp;
        double ln = R[i] - L[i] + 1; 
        for(int j = L[i]; j <= R[i]; j++) {
            for (int p = j+1; p <= 100; p++) {
                rep(k, N) {
                    ans += (double)k * dp[p][k] / ln;
                }
            }
            dpN[j][0] = (ln-1) * dp[j][0] / ln;
            rep(k, N) {
                dpN[j][k+1] = dp[j][k] / ln + (ln-1) * dp[j][k+1] / ln;
            }
        }
        swap(dp, dpN);
    }
    printf("%.10f\n", ans);
    return 0;
}