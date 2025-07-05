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
    ll N, M, K;
    cin >> N >> M >> K;
    set<pair<int,int>> st;
    vector elroot(N, vector<int>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        elroot[u].push_back(v);
        elroot[v].push_back(u);
    }
    rep(i,N) elroot[i].push_back(i);
    vector<mint> dp(N);
    dp[0] = 1;
    rep(k, K) {
        mint sm = 0;
        rep(i,N) sm += dp[i];

        vector<mint> dp_new(N, sm);
        rep(i, N) {
            for(auto nx: elroot[i]) {
                dp_new[i] -= dp[nx];
            }
        }
        swap(dp, dp_new);
    }
    cout<<dp[0].val()<<endl;
    return 0;
}
