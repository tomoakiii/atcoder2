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
    string S; int K;
    cin >> S >> K;
    int N = S.size();
    vector dp(N, vector(K+1, vector<ll>(2,-1)));
    auto func = [&](auto func, int cur, int krem, int isany)->ll{
        if(dp[cur][krem][isany] != -1) return dp[cur][krem][isany];
        int p = S[cur] - '0';
        if(krem == 0) {
            dp[cur][krem][isany] = 1;
        } else if (cur == N-1) {
            if(krem == 1) {      
                if(isany) {
                    dp[cur][krem][isany] = 9;
                } else if (p == 0) {
                    dp[cur][krem][isany] = 0;
                } else {
                    dp[cur][krem][isany] = p;
                }
            } else {
                dp[cur][krem][isany] = 0;
            }
        } else if(isany) {
            dp[cur][krem][isany] = func(func, cur+1, krem, 1) + (9 * func(func, cur+1, krem-1, 1));
        } else {
            if(p == 0) {
                dp[cur][krem][isany] = func(func, cur+1, krem, 0);
            } else {
                dp[cur][krem][isany] = func(func, cur+1, krem-1, 0) + (p-1) * func(func, cur+1, krem-1, 1) + func(func, cur+1, krem, 1);
            }
        }
        return dp[cur][krem][isany];
    };
    cout << func(func, 0, K, 0) << endl;
    return 0;
}