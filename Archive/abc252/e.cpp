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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<ll, pair<int, int>>>{});
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].push_back({c, {v, i}});
        uv[v].push_back({c, {u, i}});
    }
    rep(i, N) {
        sort(uv[i].begin(), uv[i].end());
    }
    vector<ll> visit(N, INF);
    priority_queue<pair<pair<ll, int>, int>> que;
    que.push({{0, 0}, -1});
    vector<int> ans{};
    visit[0] = 0;
    while(!que.empty()) {
        auto [x1, i] = que.top();
        auto [c, q] = x1;
        que.pop();
        c *= -1;
        if(visit[q] < c) continue;
        if(i>=0) ans.emplace_back(i);
        for(auto [c2, pni]: uv[q]) {
            auto [nx, id] = pni;
            if(visit[nx] <= visit[q] + c2) {
                continue;
            }
            visit[nx] = visit[q] + c2;
            que.push({{-visit[nx], nx}, id});
       }
    }
    for(auto i: ans){
        cout << i+1 << " ";
    }
    cout << endl;
    return 0;
}