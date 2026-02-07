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
int main() {
    int N,M; cin>>N>>M;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll c;
        cin>>u>>v>>c;
        u--,v--;
        uv[u].push_back({v,c});
        uv[v].push_back({u,c});
    }
    priority_queue<pli,vector<pli>,greater<pli>> que;
    que.push({0,0});
    vector<ll> dist(N,INF);
    dist[0] = 0;
    vector<int> pre(N,-1);
    while(!que.empty()) {
        auto [d, q] = que.top();
        que.pop();
        if(dist[q] < d) continue;
        for(auto [nx,c]: uv[q]) {
            if(dist[nx] <= dist[q] + c) continue;
            dist[nx] = dist[q] + c;
            pre[nx] = q;
            que.push({dist[nx], nx});
        }
    }
    vector<int> ans;
    int st = N-1;
    while(st != -1) {
        ans.push_back(st+1);
        st = pre[st];
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans) cout << a << " ";
    cout << endl;
}