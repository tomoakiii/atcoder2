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
typedef modint998244353 mint;

int main(){
    ll N, M, K, S, T, X;
    cin>>N>>M>>K>>S>>T>>X;
    S--, T--, X--;
    vector uv(N, vector<int>{});
    rep(i,M){
        int u, v;
        cin>>u>>v;
        u--,v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    vector dp(K+1, vector(N, vector<mint>(2)));
    dp[0][S][0] = 1;
    rep(i,K) rep(j,N) {
        for(auto nx: uv[j]){
            if(nx==X){
                dp[i+1][nx][1] += dp[i][j][0];
                dp[i+1][nx][0] += dp[i][j][1];
            } else {
                dp[i+1][nx][0] += dp[i][j][0];
                dp[i+1][nx][1] += dp[i][j][1];
            }
            // cout<<nx<<" "<<j<<" "<<dp[i+1][nx][1].val()<<" "<<dp[i+1][nx][0].val()<<endl;
        }
    }
    cout << dp[K][T][0].val() << endl;
    return 0;
}