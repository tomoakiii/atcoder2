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
typedef pair<ll,int> pli;
int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        ll w;
        cin>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }

    int s, K; cin>>s>>K;
    s--;
    vector dist(K+1, vector<ll>(N,INF));
    vector<int> d(K+1);
    d[0] = s;
    rep(i,K) {
        cin>>d[i+1];
        d[i+1]--;
    }

    rep(k,K+1) {
        int s = d[k];
        dist[k][s]=0;
        priority_queue<pli,vector<pli>,greater<pli>> que;
        que.push({dist[k][s],s});
        while(!que.empty()){
            auto [d,cur] = que.top();
            que.pop();
            if(dist[k][cur]<d) continue;
            for(auto [nx,w]: uv[cur]) {
                if(chmin(dist[k][nx], dist[k][cur]+w)) {
                    que.push({dist[k][nx],nx});
                }
            }
        }
    }

    vector dest(K+1, vector<ll>(K+1));
    rep(k,K+1) {
        int s = d[k];
        rep(j,K+1) {
            dest[k][j] = dist[k][d[j]];
        }
    }

    ll ful=1ll<<(K+1);
    vector dp(ful, vector<ll>(K+1,INF));
    dp[1][0] = 0;
    rep(S, ful) {
        for(int from=0;from<=K;from++) {
            if(dp[S][from] >= INF) continue;
            for(int to=1;to<=K;to++){
                if((S>>to & 1)) continue;
                chmin(dp[S|(1ll<<to)][to], dp[S][from] + dest[from][to]);
            }
        }
    }
    ll ans=INF;
    for(int i=1;i<=K;i++) {
        chmin(ans, dp[ful-1][i] + dest[i][0]);
    }
    cout<<ans<<endl;
    return 0;
}