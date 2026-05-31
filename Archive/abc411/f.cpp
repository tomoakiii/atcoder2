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
    vector<pair<int,int>> uvm(M);
    vector<set<int>> edge(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
        uvm[i] = {u,v};
        edge[u].insert(v);
        edge[v].insert(u);
    }
    ll Q; cin>>Q;
    dsu UF(N);
    ll ans = M;
    vector<set<int>> piece(N);
    rep(i,N) piece[i].insert(i);
    while(Q--) {
        ll x; cin>>x; x--;
        auto [u,v] = uvm[x];
        int u2 = 
        if(edge[u].contains(v)) {
            UF.merge(u,v);
            int l = UF.leader(u);
            ans--;
            edge[l].erase(v);
            edge[v].erase(u);
            for(auto nx: edge[v]) {
                if(edge[l].contains(nx)) ans--;
                else edge[u].insert(nx);
            }
            edge[v].clear();
        }
        cout << ans << endl;
    }

    return 0;
}