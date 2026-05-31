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
typedef modint1000000007 mint;
typedef pair<int, int> pii;
typedef pair<ll, pii> pli;
typedef tuple<int, int, int, int> tiii;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pli> uv(M);
    rep(i,M) {
        ll R;
        int u,v; cin>>R>>u>>v; u--, v--;
        pli p;
        p.first = R;
        p.second = {u,v};
        uv[i] = p;
    }
    sort(uv.begin(), uv.end());
    dsu UF(N+1);
    ll ans = 0;
    for(auto [R, ij]: uv) {
        auto [u,v] = ij;
        if(!UF.same(u,v+1)) {
            ans += R;
            UF.merge(u,v+1);
        }
    }
    rep(i,N+1) {
        if(UF.leader(0) != UF.leader(i)) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}