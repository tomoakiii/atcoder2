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
typedef pair<int, int> pii;
typedef pair<ll, pii> plii;

int main(){
    ll N, M, X;
    cin >> N >> M >> X;
    vector uv(N, vector<pii>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].push_back({v, 0});
        uv[v].push_back({u, 1});
    }
    
    priority_queue<plii, vector<plii>, greater<plii>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    vector dis(2, vector<ll>(N, INF));
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
        auto [d, ppp] = pq.top();
        auto [p, b] = ppp;
        pq.pop();
        if(p == N-1) {
            cout << min(dis[0][N-1], dis[1][N-1])  << endl;
            return 0;
        }        
        for(auto [np, nb] : uv[p]) {
            if(b == nb) {
                if(dis[b][np] <= dis[b][p] + 1) continue;
                dis[b][np] = dis[b][p] + 1;
                pq.push({dis[b][np], {np, b}});
            } else {
                if(dis[nb][np] <= dis[b][p] + X + 1) continue;
                dis[nb][np] = dis[b][p] + X + 1;
                pq.push({dis[nb][np], {np, nb}});
            }
        }
    }
    return 0;
}