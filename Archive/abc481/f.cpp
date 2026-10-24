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
typedef modint998244353 mint;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(w,v);
    }
    rep(i,N){
        sort(uv[i].begin(), uv[i].end());
    }
    vector<mint> ans(N);
    vector<ll> dist(N, INF);
    dist[0] = 0;

    typedef pair<pair<ll,ll>, pair<ll,ll>> pll; // {original rank, value} {current, from}
    priority_queue<pll,vector<pll>,greater<pll>>que;
    que.push({{0,0}, {0,0}});
    vector<ll> ranks(N,INF);
    int id = -1;
    map<pair<ll,ll>, ll> mp;
    while(!que.empty()){
        auto [ov, cf] = que.top();
        auto [rank, val] = ov;
        auto [cur, from] = cf;
        que.pop();
        if(ranks[cur] != INF)continue;
        if(!mp.contains(ov)) {
            id++;
            mp[ov] = id;
        }
        ranks[cur] = mp[ov];
        ans[cur] = val + 10*ans[from];
        for(auto [w,nx] : uv[cur]) {
            if(ranks[nx] != INF)continue;
            que.push({{ranks[cur], w}, {nx, cur}});
        }
    }
    rep(i,N-1)cout<<ans[i+1].val()<<endl;
    return 0;
}