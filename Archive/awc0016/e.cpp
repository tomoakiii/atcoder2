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
typedef pair<ll, pair<ll,int>> pli;
int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,ll>>{});
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    int S,T; cin>>S>>T; S--,T--;
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].push_back({v,w});
        uv[v].push_back({u,w});
    }
    ll F=1ll<<N;
    vector dp(F, vector<ll>(N,-INF));
    priority_queue<pli> que;
    dp[1<<S][S] = P[S];
    que.push({P[S], {1<<S, S}});
    while(!que.empty()){
        auto [v,ki] = que.top();
        auto [k,i] = ki;
        que.pop();
        if(dp[k][i] > v) continue;
        for(auto [j, w]: uv[i]) {
            ll nk = k|(1ll<<j);
            if(k>>j & 1) {
                if(chmax(dp[nk][j], dp[k][i]-w)) {
                    que.push({dp[nk][j], {nk, j}});
                }
            } else if(chmax(dp[nk][j], dp[k][i]+P[j]-w)){
                que.push({dp[nk][j], {nk, j}});
            }
        }
    }
    ll ans = -INF;
    rep(k,F) if(k>>T & 1) chmax(ans, dp[k][T]);
    cout<<ans<<endl;
    return 0;
}