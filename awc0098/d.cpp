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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,K,Q;
    cin >> N >> M >> K >> Q;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];

    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    vector dp(N, vector<ll>(K, -INF));
    typedef pair<ll,ll> pll;
    queue<pll> que;
    rep(i,N){
        dp[i][0] = P[i]%Q;
    }
    for(int d=2; d<=K; d++){
        rep(i,N){
            for(auto nx:uv[i]){
                chmax(dp[nx][d-1], dp[i][d-2] + (d*P[nx])%Q);
            }
        }
    }
    ll ans=-INF;
    rep(i,N) chmax(ans, dp[i][K-1]);
    cout<<ans<<endl;
    return 0;
}