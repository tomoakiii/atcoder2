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
typedef pair<ll, int> pli;
int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<int>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push({0,0});
    vector<ll> dist(N,INF); dist[0] = 0;
    while(!que.empty()) {
        auto [d, i] = que.top();
        que.pop();
        if(dist[i] < d)  continue;
        for(auto nx: uv[i]) {
            if(dist[nx] <= d + 1) continue;
            dist[nx] = d + 1;
            que.push({d+1, nx});
        }
    }
    rep(i,N) {
        cout << ((dist[i]==INF)?-1:dist[i]) << endl;
    }
    return 0;
}