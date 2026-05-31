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
    cin >> N;
    vector uv(N, vector<int>{});
    scc_graph G(N);
    rep(i,N) {
        int u,v; cin>>u>>v;
        u--,v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    vector<bool> visit(N);
    pair<int,int> db;
    auto dfs = [&](auto dfs, int cur, int pre)->void{
        visit[cur]=true;
        for(auto nx: uv[cur]){
            if(nx==pre) continue;
            if(visit[nx]) {
                G.add_edge(cur, nx);
                continue;
            }
            G.add_edge(cur, nx);
            dfs(dfs, nx, cur);
        }
    };
    dfs(dfs,0,-1);
    unordered_set<int> st;
    dsu UF2(N);
    for(auto gg: G.scc()){
        if(gg.size() <= 1) continue;
        for(auto g:gg) {
            st.insert(g);
        }
    }
    for(auto s:st) {
        auto func=[&](auto func, int cur, int pre)->void{
            for(auto nx:uv[cur]){
                if(st.contains(nx))continue;
                if(nx==pre) continue;
                UF2.merge(cur,nx);
                func(func, nx, cur);
            }
        };
        func(func, s, -1);
    }
    int Q; cin>>Q;
    while(Q--) {
        int u,v; cin>>u>>v; u--,v--;
        if(UF2.same(u,v)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}