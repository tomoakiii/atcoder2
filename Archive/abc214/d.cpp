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
typedef pair<int,int> pii;
int main(){
    ll N;
    cin >> N;
    vector<pair<ll, pii>> U(N-1);
    dsu UF(N);
    rep(i,N-1) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;        
        pii p = {u,v};
        U[i] = {w, p};        
    }
    sort(U.begin(), U.end());
    ll ans = 0;
    rep(i,N-1) {
        auto [w, p] = U[i];
        auto [u, v] = p;
        ans += w * (ll)UF.size(u) * (ll)UF.size(v);
        UF.merge(u,v);
    }
    cout << ans << endl;
    return 0;
}