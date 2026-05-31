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
    ll A,B,C;
    cin >> A >> B >> C;
    vector dp(101, vector(101, vector<double>(101, 0)));
    auto func = [&](auto func, int a, int b, int c) -> double{
        if(a==100 || b == 100 || c == 100) {
            return 0;
        }
        if(dp[a][b][c] > 0) return dp[a][b][c];
        dp[a][b][c] = (1.+func(func,a+1,b,c)) * (double)(a)/(a+b+c)
            + (1.+func(func,a,b+1,c)) * (double)(b)/(a+b+c)
            + (1.+func(func,a,b,c+1)) * (double)(c)/(a+b+c);
        return dp[a][b][c];
    };
    printf("%.10f\n", func(func,A,B,C));
    return 0;
}