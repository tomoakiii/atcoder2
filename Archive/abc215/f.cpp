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
    vector<bool> visit(N);
    auto f = [&](auto f, int cur)->ll{
        visit[cur] = true;
        ll sm = 0;
        for(auto nx: uv[cur]){
            if(visit[nx]) continue;
            par[nx] = cur;
            chld[nx] = f(f, nx);
            sm += 2* chld[nx];
        }        
        return sm + 1;
    };
    chld[0] = f(f, 0);

    cout<<chld[0]<<endl;
    for(int i=1; i<N; i++){
        ll t = chld[par[i]] - 2*chld[i] - 1;
        cout<<chld[i] + 2*t+1<<endl;
    }    
    return 0;
}