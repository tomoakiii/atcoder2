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
typedef pair<ll, int> pli;
int main(){
    int N, M;
    cin >> N >> M;
    vector uv(N, vector<int>{}), vu(N, vector<int>{});
    ll ans = 0;
    scc_graph G(N);
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    rep(i,M){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        vu[v].emplace_back(u);
        G.add_edge(u, v);
    }

    for(auto gv: G.scc()) {
        if(gv.empty()) continue;
        ll s = gv.size();
        ans += s * (s-1) / 2;
    }

    cout << ans << endl;
    return 0;
}