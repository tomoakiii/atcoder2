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

    ll N, M;
    cin >> N; M=N-1;
    vector uv(N, vector<ll>{});
    vector<pair<ll,ll>> AB(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
        AB[i]={u,v};
    }
    vector<ll> Nch(N);
    vector<ll> dst(N);
    // count child
    auto dfs0 = [&](auto dfs0, int cur, int pre=-1, int d)->void{
        ll ret = 1;
        dst[cur]=d;
        for(auto nx:uv[cur]){
            if(nx==pre)continue;
            dfs0(dfs0, nx, cur, d+1);
            ret+=Nch[nx];
        }
        Nch[cur]=ret;
    };
    dfs0(dfs0, 0, -1, 0);

    vector<ll> dwn(N,0);
    ll sm = 0;
    rep(i,M){
        auto [u,v]=AB[i];
        if(dst[u] > dst[v]) swap(u,v);
        if(Nch[v] > N-Nch[v]) {
            dwn[v]+=i+1;
        } else {
            sm+=i+1;
            dwn[v]-=i+1;
        }
    }

    auto dfs1 = [&](auto dfs1, int cur, int pre=-1)->void{
        for(auto nx:uv[cur]){
            if(nx==pre)continue;
            dwn[nx]+=dwn[cur];
            dfs1(dfs1, nx, cur);
        }
    };
    dfs1(dfs1, 0, -1);

    rep(i,N){
        cout << sm + dwn[i] <<" \n"[i==N-1];
    }
    return 0;
}