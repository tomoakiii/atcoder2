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
    ll N,M,F;
    cin >> N >> M >> F;

    vector<ll> R(N);
    rep(i,N) cin>>R[i];

    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        ll w; cin>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    ll hp=F+R[0];
    ll full = 1ll<<N;
    vector mp(full, vector<ll>(N,-1));
    mp[1][0] = hp;
    ll ans=-1;
    auto dfs=[&](auto dfs, ll root, int cur, ll hp)->void{
        if(cur==N-1) chmax(ans,hp);
        for(auto [nx,w]:uv[cur]){
            if(w > hp) continue;
            ll nhp = hp-w;
            if(!(root>>nx & 1)) nhp+=R[nx];
            ll nroot=root|(1ll<<nx);
            if(mp[nroot][nx] > nhp) continue;
            mp[nroot][nx] = nhp;
            dfs(dfs,nroot,nx,nhp);
        }
    };
    dfs(dfs,1,0,hp);
    cout<<ans<<endl;
    return 0;
}