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
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    ll K; cin>>K;

    vector<int> C(K);
    vector D(K, vector<ll>(K));

    rep(i,K) {
        cin>>C[i]; C[i]--;
    }
    rep(i,K) {
        ll c = C[i];
        vector<ll> dist(N,INF);
        dist[c] = 0;
        queue<int> que;
        que.push(c);
        while(!que.empty()){
            auto q = que.front();
            que.pop();
            for(auto nx : uv[q]){
                if(dist[nx] <= dist[q] + 1) continue;
                dist[nx] = dist[q] + 1;
                que.push(nx);
            }
        }
        rep(j,K) {
            D[i][j] = dist[C[j]];
        }
    }
    vector dp(1ll<<K, vector<ll>(K, INF));
    rep(i,K) dp[1ll<<i][i] = 0;
    rep(k,1ll<<K) {
        rep(j,K) { // last j
            if(dp[k][j] == INF) continue;
            rep(i,K) { // inserting i
                chmin(dp[k | 1ll<<i][i], dp[k][j] + D[i][j]);
            }
        }
    }
    ll ans = INF;
    rep(i,K) chmin(ans, dp[(1ll<<K) - 1][i]);
    if(ans >= INF) cout<<-1<<endl;
    else cout<<ans+1<<endl;
    return 0;
}