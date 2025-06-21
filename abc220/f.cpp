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
    M = N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<int> par(N,-1);
    vector<ll> chld(N);
    vector<ll> node(N);
    vector<bool> visit(N);
    auto f = [&](auto f, int cur)->void{
        visit[cur] = true;
        for(auto nx: uv[cur]){
            if(visit[nx]) continue;
            f(f, nx);
            chld[cur] += chld[nx];
            node[cur] += node[nx];
            par[nx] = cur;            
        }
        chld[cur] += node[cur];
        node[cur]++;
    };
    f(f, 0);

    vector<ll> ans(N);
    ans[0] = chld[0];
    vector<bool> visit2(N);
    auto f2 = [&](auto f2, int cur)->void{
        visit2[cur] = true;
        if(cur != 0) {
            ll t = ans[par[cur]] - chld[cur] - node[cur];
            ans[cur] = chld[cur] + t + (N-node[cur]);
        }
        for(auto nx: uv[cur]){
            if(visit2[nx]) continue;            
            f2(f2, nx);
        }
    };
    f2(f2,0);
    rep(i,N) cout<<ans[i]<<endl;
    
    return 0;
}