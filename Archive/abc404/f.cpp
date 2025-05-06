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


void partitions(int n, int max_n, vector<int>& v, vector<vector<int> >& vv)
{
    if (n == 0) {
        vv.push_back(v);
        return;
    }
    for (int i = min(n, max_n); i > 0; i--) {
        v.push_back(i);
        partitions(n - i, i, v, vv);
        v.pop_back();
    }    
}
int main(){
    int N, T, M, K;
    cin >> N >> T >> M >> K;
    vector dp(T+1, vector<double>(K+1));
    dp[T][K] = 1.;
    vector<vector<int>> vv{};
    vector<int> vt{};
    partitions(M, M, vt, vv);

    for(int i=T-1; i>=0; i--) {
        rep(j, K+1) {
            double mx = 0;
            for(auto v: vv) {
                if(v.size() > N) continue;
                double x = 0;
                for(auto p: v){
                    x += dp[i+1][min(j+p, K)];
                }
                x += (N - v.size()) * dp[i+1][j];
                chmax(mx, x);
            }
            mx /= N;            
            dp[i][j] = mx;
        }
    }
    printf("%.10f\n", dp[0][0]);
    return 0;
}