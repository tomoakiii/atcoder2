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

    ll N, M, K;
    cin >> N >> M >> K;
    vector uv(N, vector<pair<ll,ll>>{});
    rep(i,M) {
        int u,v;
        ll t;
        cin>>u>>v>>t;
        u--, v--;
        uv[u].emplace_back(v,t);
        uv[v].emplace_back(u,t);
    }
    vector<ll> P(K);
    rep(i,K) {
        cin>>P[i];
        P[i]--;
    }
    P.push_back(N-1);
    K++;
    int cur = 0;
    ll ans = 0;
    rep(i,K) {
        int dest = P[i];
        vector<ll> dist(N,INF);
        dist[cur] = 0;
        priority_queue<pli, vector<pli>, greater<pli>> que;
        que.push({0,cur});
        while(!que.empty()) {
            auto [d,i] = que.top();
            que.pop();
            if(dist[i] < d) continue;
            for(auto [nx, t]: uv[i]) {
                if(dist[nx] <= dist[i]+t) continue;
                dist[nx] = dist[i] + t;
                que.push({dist[nx],nx});
            }
        }
        if(dist[dest] == INF) {
            cout<<-1<<endl;
            return 0;
        }
        cerr<<dist[dest]<<endl;
        ans += dist[dest];
        cur = dest;
    }
    cout<<ans<<endl;
    return 0;
}