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
    M=N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    int ind=1;
    vector<pair<int,int>> LR(N, {INF, -INF});

    auto dfs = [&](auto dfs, int cur, int pre, int p)->void{
        if(uv[cur].size() == 1 && uv[cur][0] == pre) {
            LR[cur] = {ind,ind};
            ind++;
            return;
        }
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            dfs(dfs, nx, cur, p);
            chmin(LR[cur].first, LR[nx].first);
            chmax(LR[cur].second, LR[nx].second);
        }
        return;
    };
    dfs(dfs,0,-1,1);
    for(auto [l,r]:LR) {
        cout<<l<<" "<<r<<endl;
    }
    return 0;
}