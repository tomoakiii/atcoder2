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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> H(N);
    rep(i,N) cin >> H[i];
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> dist(N, INF);
    dist[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (ll v : uv[u]) {
            ll e = abs(H[u] - H[v]);
            if(e > K) continue;
            ll nd = d + e;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    if(dist[N-1] == INF) cout << -1 << endl;
    else cout << dist[N-1] << endl;  
    return 0;
}