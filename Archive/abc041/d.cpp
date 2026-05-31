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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    vector vu(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        vu[v].emplace_back(u);
    }
    vector<ll> dp(1ll<<N, 0);
    dp[0] = 1;
    rep(S,1ll<<N) {
        rep(i, N) {
            if(S>>i & 1) continue;
            bool flg = true;
            for(auto u: vu[i]){
                if( !(S>>u & 1) ) flg = false;
            }
            if(flg) dp[S|(1ll<<i)] += dp[S];
        }
    }
    cout<<dp[(1ll<<N)-1]<<endl;
    return 0;
}