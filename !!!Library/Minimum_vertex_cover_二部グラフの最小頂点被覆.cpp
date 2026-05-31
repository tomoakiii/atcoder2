//https://atcoder.jp/contests/awc0071/editorial/19872
// 0-1の色で交互に塗分けられた二部グラフがあり、ある辺を選んだときに辺に接する両頂点が覆われたものとする。
// すべての頂点を覆うためには、何本の辺を選べばよいか？
// 最大フロー： 超頂点Sから、色0の頂点すべてにcap=1の辺を張り、
// 各辺ごとに色0→色1の頂点にcap=1の辺を張り、
// 色1の頂点から超頂点Gにcap=1の辺を張る。
//

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<bool> visit(N);
    vector<bool> col(N);
    mf_graph<int> MG(N+2);
    rep(i,N){
        if(visit[i])continue;
        vector<int> c0, c1;
        vector<pair<int,int>> ed;
        auto dfs=[&](auto dfs, int cur, bool c)->void{
            visit[cur]=true;
            col[cur]=c;
            for(auto nx:uv[cur]){
                if(visit[nx])continue;
                dfs(dfs,nx,!c);
            }
        };
        dfs(dfs,i,false);
    }
    rep(i,N) {
        if(!col[i]) {
            MG.add_edge(N,i,1);
            for(auto nx:uv[i]) {
                MG.add_edge(i,nx,1);
            }
        } else {
            MG.add_edge(i,N+1,1);
            for(auto nx:uv[i]) {
                MG.add_edge(nx,i,1);
            }
        }
    }
    auto ans=MG.flow(N,N+1);
    cout<<ans<<endl;
    return 0;
}