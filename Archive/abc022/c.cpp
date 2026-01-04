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
typedef pair<ll, pli> pl;
int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,int>>{});
    vector<ll> C(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v>>C[i];
        u--, v--;
        uv[u].emplace_back(v,i);
        uv[v].emplace_back(u,i);
    }
    ll ans = INF;
    for(auto [nx, i]: uv[0]) {
        vector<ll> dist(N, INF);
        priority_queue<pl, vector<pl>, greater<pl>> que;
        dist[nx] = C[i];
        que.push({C[i], {C[i], nx}});
        while(!que.empty()) {
            auto [c, cnx] = que.top();
            que.pop();
            auto [d, j] = cnx;
            if(dist[j] < d) continue;
            for(auto [nnx, k] : uv[j]) {
                if(k == i) continue;
                if(dist[nnx] <= dist[j] + C[k]) continue;
                dist[nnx] = dist[j] + C[k];
                que.push({C[k], {dist[nnx], nnx}});
            }
        }
        chmin(ans, dist[0]);
    }
    if(ans == INF) cout<<-1<<endl;
    else cout << ans << endl;
    return 0;
}