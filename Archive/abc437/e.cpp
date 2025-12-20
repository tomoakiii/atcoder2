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
    ll N;
    cin >> N;
    vector<map<ll,int>> cont(N+1);
    vector UF(N+1, vector<int>{});
    rep(i,N+1) UF[i].push_back(i);

    vector<int> REP(N+1);
    rep(i,N+1) REP[i] = i;
    for(int i=1;i<=N; i++) {
        ll u,v; cin>>u>>v;
        u = REP[u];
        if(cont[u].contains(v)) {
            UF[cont[u][v]].push_back(i);
            REP[i] = cont[u][v];
        } else {
            cont[u][v] = i;
        }
    }


    vector<int> ans;
    auto dfs = [&](auto dfs, int cur)->void{
        for(auto u: UF[cur]) ans.push_back(u);
        for(auto [v,i]:cont[cur]) {
            dfs(dfs, i);
        }
    };
    dfs(dfs, 0);
    if(ans.size() != N+1) {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=N; i++) cout<<ans[i]<<endl;
    return 0;
}