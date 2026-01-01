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
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppp;
typedef pair<pll, pll> pil;
int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ppp>{});
    rep(i,M) {
        int u,v; ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].push_back({v,{c, i}});
        uv[v].push_back({u,{c, i}});
    }
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<int> used(M);
    rep(i,N) {
        que.push({0,i});
        vector<ll> dist(N,INF);
        dist[i] = 0;
        vector hist(M, vector<ll>(N,INF));
        while(!que.empty()) {
            auto [dummy, cur] = que.top();
            que.pop();
            for(auto [nx, ci]: uv[cur]) {
                auto [c, j] = ci;
                if(dist[nx] == dist[cur] + c) {
                    hist[j][nx] = dist[nx];
                    continue;
                }
                if(dist[nx] < dist[cur] + c) continue;
                dist[nx] = dist[cur] + c;
                hist[j][nx] = dist[nx];
                que.push({c,nx});
            }
        }
        rep(j,M) rep(k,N) {
            if(hist[j][k] == dist[k]) used[j] = true;
        }
    }
    ll ans = 0;
    for(auto u: used) if(!u) ans++;
    cout << ans << endl;
    return 0;
}