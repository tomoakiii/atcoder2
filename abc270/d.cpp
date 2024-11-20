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
    ll N, M, K;
    cin >> N >> M >> K;
    vector uv(N, vector<pair<int, ll>>{});
    rep(i,M) {
        int u, v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].push_back({v, c});
    }
    vector<int> E(K);
    rep(i,K) {
        cin>>E[i];
        E[i]--;
    }
    vector<ll> dist(N, INF);
    map<int, int> mp;
    rep(i,K) {
        mp[E[i]] = i;
    }
    bool flg = false;
    auto f=[&](auto f, int cur, int d)->void {
        if (cur == N-1) {
            flg = true;
            return;
        }
        for (auto [nx, nd] : uv[cur]){            
            if (dist[nx] < d+nd) {
                continue;
            }
            if(mp.count(nx)) continue;
            if(mp[nx] < mp[cur]) continue;
            dist[nx] = d+nd;
            f(f, nx, d+nd);
        }        
    };
    dist[0] = 0;
    f(f, 0, 0);
    if(dist[N-1] == INF) cout << -1 << endl;
    else cout << dist[N-1] << endl;
    return 0;
}