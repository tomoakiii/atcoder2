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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    scc_graph G(N);
    vector uv(N,vector<int>{});
    vector<int>T(N);
    rep(i,N){
        int t; cin>>t; t--;
        G.add_edge(i,t);
        uv[t].push_back(i);
        T[i]=t;
    }
    vector<int> cnt(N);
    for(auto gg:G.scc()){
        if(gg.size()>1){
            for(auto g:gg){
                cnt[g]=gg.size();
            }
        }
    }
    rep(i,N){
        if(cnt[i]==0)continue;
        auto dfs = [&](auto dfs, int cur, int d)->void{
            cnt[cur]=d;
            for(auto nx:uv[cur]){
                if(cnt[nx]>0)continue;
                dfs(dfs,nx,d+1);
            }
        };
        dfs(dfs, i, cnt[i]);
    }
    while(Q--){
        int s; cin>>s; s--;
        cout<<cnt[s]<<endl;
    }
    return 0;
}