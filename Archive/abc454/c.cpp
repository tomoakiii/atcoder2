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
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    vector<bool> visit(N);
    auto dfs=[&](auto dfs, int cur)->void{
        visit[cur]=true;
        for(auto nx:uv[cur]) {
            if(visit[nx])continue;
            dfs(dfs,nx);
        }
    };
    dfs(dfs,0);
    ll ans=0;
    rep(i,N) {
        if(visit[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}