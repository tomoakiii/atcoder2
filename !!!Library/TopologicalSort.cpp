// https://atcoder.jp/contests/awc0186/tasks/awc0186_e
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

// Topologicalではない（閉路を持つ）場合、ordのサイズがNではない
vector<int> TopologicalSort(vector<vector<int>> uv){
    int V = uv.size();
    int E = uv[0].size();
    vector<int> ind(V, 0);
    rep(u,V) for(auto v:uv[u]) ind[v]++;
    queue<int> que;
    rep(i,V) if(ind[i] == 0) que.push(i);
    vector<int> ord;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ord.push_back(u);
        for (auto v:uv[u]) {
            ind[v]--;
            if (ind[v] == 0) que.push(v);
        }
    }
    return ord;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<int>{});
    vector<ll> A(N), C(N);
    rep(i,N)cin>>A[i];
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    auto V = TopologicalSort(uv);
    if(V.size()!=N){
        cout << -1 << endl;
        return 0;
    }
    //rep(i,N)cerr<<V[i]<<" \n"[i==N-1];
    vector<ll> dist(N);
    ll ans = 0;
    for(auto u:V){
        chmax(ans, dist[u]+A[u]);
        for(auto v:uv[u]){
            chmax(dist[v], dist[u]+A[u]);
        }
    }
    cout << ans << endl;
    return 0;
}