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

int main() {
    int N,M; cin>>N>>M;
    vector uv(N, vector<int>{});
    rep(i,M) {
        int u,v; cin>>u>>v;
        u--,v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    queue<int> que;
    que.push(0);
    vector<int> dist(N,INFi);
    dist[0] = 0;
    vector<int> pre(N,-1);
    while(!que.empty()) {
        auto q = que.front();
        que.pop();
        for(auto nx: uv[q]) {
            if(dist[nx] != INFi) continue;
            pre[nx] = q;
            que.push(nx);
            dist[nx] = dist[q] + 1;
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