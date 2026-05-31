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
    vector dist(N, vector<ll>(N,INF));
    rep(i,N) dist[i][i]=0;
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        dist[u][v] = w;
    }
    rep(k,N) rep(i,N) rep(j,N) chmin(dist[i][j], dist[i][k] + dist[k][j]);

    int S,K; cin>>S>>K; S--;
    vector<int> T(K);
    rep(i,K) {
        cin>>T[i];
        T[i]--;
    }

    ll full = 1ll<<K;
    vector dp(full, vector<ll>(K,INF));
    rep(i,K) {
        dp[1ll << i][i]=dist[S][T[i]];
    }
    rep(S,full) {
        rep(i,K) {
            if(dp[S][i]==INF) continue;
            rep(j,K) {
                chmin(dp[S|(1ll<<j)][j], dp[S][i] + dist[T[i]][T[j]]);
            }
        }
    }
    ll ans = INF;
    rep(i,K) chmin(ans, dp[full-1][i] + dist[T[i]][S]);
    if(ans>=INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}